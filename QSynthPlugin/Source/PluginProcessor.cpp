/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "NewComponent.h"

//==============================================================================
QSynthPluginAudioProcessor::QSynthPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
    parameters(*this, nullptr, "ParamTreeIdentifier", {
        std::make_unique<juce::AudioParameterFloat>("release", "Release (s)", 0.001f, 30.0f, 10.0f), 
        std::make_unique<juce::AudioParameterFloat>("waveSpeed", "Wavespeed (m/s)", 0.001f, 10.0f, 0.5f),
        std::make_unique<juce::AudioParameterFloat>("inputLoc", "Input Location (m)", 0.001f, 1.0f, 0.1f),
        std::make_unique<juce::AudioParameterFloat>("dryWet", "Dry/Wet", 0.0f, 1.0f, 0.5f),
        std::make_unique<juce::AudioParameterFloat>("gain", "Gain", 0.0f, 1.0f, 1.0f),
        std::make_unique<juce::AudioParameterFloat>("width", "PulseWidth", 0.0f, 1.0f, 0.01f),
        std::make_unique<juce::AudioParameterFloat>("quality", "Quality Factor", 0.3f, 1.0f, 1.0f),
        })

{
    releaseParam = parameters.getRawParameterValue("release");
    waveSpeedParam = parameters.getRawParameterValue("waveSpeed");
    inputLocParam = parameters.getRawParameterValue("inputLoc");
    dryWetParam = parameters.getRawParameterValue("dryWet");
    GainParam = parameters.getRawParameterValue("gain");
    widthParam = parameters.getRawParameterValue("width");
    qualityParam = parameters.getRawParameterValue("quality");

    for (int i = 0; i < voiceCount; i++)
    {
        synth.addVoice(new QEnvVoice());
    }

    synth.addSound(new QEnvSound()); 
}

QSynthPluginAudioProcessor::~QSynthPluginAudioProcessor()
{
}

//==============================================================================
const juce::String QSynthPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool QSynthPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool QSynthPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool QSynthPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double QSynthPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int QSynthPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int QSynthPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void QSynthPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String QSynthPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void QSynthPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void QSynthPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    tempBuffer.setSize(getTotalNumOutputChannels(), samplesPerBlock);
    synth.setCurrentPlaybackSampleRate(sampleRate);
    for (int i = 0; i < voiceCount; i++)
    {
        QEnvVoice* v = dynamic_cast<QEnvVoice*>(synth.getVoice(i));
        v->init(sampleRate);
    }
}

void QSynthPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool QSynthPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void QSynthPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    jassert(totalNumInputChannels > 0);

    tempBuffer.makeCopyOf(buffer);


    for (int i = 0; i < voiceCount; i++)
    {
        QEnvVoice* v = dynamic_cast<QEnvVoice*>(synth.getVoice(i));
        v->setRelease(*releaseParam);
        v->setWaveSpeed(*waveSpeedParam);
        v->setInputLoc(*inputLocParam);
        v->setInputBuffer(tempBuffer);
        v->setGain(*dryWetParam, *GainParam);
        v->setWidth(*widthParam);
        v->setQuality(*qualityParam);
    }
    
    for (int c = 0; c < totalNumOutputChannels; ++c)
    {
        auto* output = buffer.getWritePointer(c);
        for (int i = 0; i < buffer.getNumSamples(); ++i)
        {
            output[i] = 0;
        }
    }

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool QSynthPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* QSynthPluginAudioProcessor::createEditor()
{
    return new juce::GenericAudioProcessorEditor (*this);
}

//==============================================================================
void QSynthPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void QSynthPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new QSynthPluginAudioProcessor();
}
