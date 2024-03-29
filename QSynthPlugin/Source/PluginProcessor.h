/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Oscillators.h"
#include "WaveSim.h"
#include "QEnveloper.h"

//==============================================================================
/**
*/
class QSynthPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    QSynthPluginAudioProcessor();
    ~QSynthPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:

    juce::AudioProcessorValueTreeState parameters;
    std::atomic<float>* releaseParam;
    std::atomic<float>* waveSpeedParam;
    std::atomic<float>* inputLocParam;
    std::atomic<float>* dryWetParam;
    std::atomic<float>* GainParam;
    std::atomic<float>* widthParam;
    std::atomic<float>* qualityParam;
   
    juce::Synthesiser synth;
    int voiceCount = 4;

    juce::AudioBuffer<float> tempBuffer;
    juce::AudioBuffer<float>* inputBuffer;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QSynthPluginAudioProcessor)
};
