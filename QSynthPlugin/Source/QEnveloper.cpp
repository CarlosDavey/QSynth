/*
  ==============================================================================

	QEnveloper.cpp
	Created: 23 April 2021
	Author:  Carlos Davey

  ==============================================================================
*/

#include "QEnveloper.h"
#define QEnveloper_cpp

#pragma once

void QEnvVoice::init(float sampleRate)
{
    env.setSampleRate(sampleRate);
    envCarrier.setSampleRate(sampleRate);

    juce::ADSR::Parameters envParams;
    envParams.attack = 0.01f;
    envParams.decay = 0.0f;
    envParams.sustain = 1.0f;
    env.setParameters(envParams);

    juce::ADSR::Parameters envCarrierParams;
    envCarrierParams.attack = 0.01f;
    envCarrierParams.decay = 0.0f;
    envCarrierParams.sustain = 1.0f;
    envCarrierParams.release = 0.1f;
    envCarrier.setParameters(envCarrierParams);

    string.setUp();

}

void QEnvVoice::setRelease(float _release)
{
    releaseVal = _release;
}

void QEnvVoice::setWaveSpeed(float _waveSpeed)
{
    waveSpeedVal = _waveSpeed;
}

void QEnvVoice::setInputLoc(float _inputLoc)
{
    inputLocVal = _inputLoc;
}

void QEnvVoice::setWidth(float _width)
{
    width = _width;
}

void QEnvVoice::startNote(int /*midiNoteNumber*/, float /*velocity*/, juce::SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
    // Update parameters of string
    string.setWidth(width);
    string.setc2(waveSpeedVal);
    string.setInputLoc(inputLocVal);
    string.setLambda(quality);

    // Setup string to be excited
    string.reset();

    // Update release value
    juce::ADSR::Parameters envParams;
    envParams.release = releaseVal;
    env.setParameters(envParams);

    // Update playing values
    playing = true;
    ending = false;

    // Initialise envelope status
    env.reset();
    env.noteOn();

    envCarrier.reset();
    envCarrier.noteOn();

}

void QEnvVoice::stopNote(float /*velocity*/, bool /*allowTailOff*/)
{
    env.noteOff();
    envCarrier.noteOff();

    ending = true;

}


void QEnvVoice::renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{

    if (playing) // check to see if this voice should be playing
    {
        // Get the left and right channel buffers
        auto* inputLeft = inputBuffer->getReadPointer(0);
        auto* inputRight = inputBuffer->getReadPointer(1);

        // iterate through the necessary number of samples (from startSample up to startSample + numSamples)
        for (int sampleIndex = startSample; sampleIndex < (startSample + numSamples); sampleIndex++)
        {
            // your sample-by-sample DSP code here!
            // An example white noise generater as a placeholder - replace with your own code

            // Update the envelopes of the processed and carrier signals
            float envVal = env.getNextSample();
            float envCarrierVal = envCarrier.getNextSample();

            // Update the string simulation
            string.process();

            // Calculate the processed signal
            auto currentSampleLeft = inputLeft[sampleIndex] * string.getLeft() * envVal;
            auto currentSampleRight = inputRight[sampleIndex] * string.getRight() * envVal;

            // Add the enveloped carrier signal to the output buffer
            outputBuffer.addSample(0, sampleIndex, inputLeft[sampleIndex] * (1.0f - dryWet) * envCarrierVal * gain);
            outputBuffer.addSample(1, sampleIndex, inputRight[sampleIndex] * (1.0f - dryWet) * envCarrierVal * gain);

            // Add the enveloped processed signal to the output buffer
            outputBuffer.addSample(0, sampleIndex, currentSampleLeft * dryWet * gain);
            outputBuffer.addSample(1, sampleIndex, currentSampleRight * dryWet * gain);
            
            // End the note if the envelope ~= 0
            if (ending)
            {
                if (envVal < 0.0001f)
                {
                    clearCurrentNote();
                    playing = false;
                }

            }

        }
    }
}


bool QEnvVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<QEnvSound*> (sound) != nullptr;
}

void QEnvVoice::setInputBuffer(juce::AudioBuffer<float>& inputCopy)
{
    inputBuffer = &inputCopy;
}

void QEnvVoice::setGain(float _dryWet, float _gain)
{
    dryWet = _dryWet;
    gain = _gain;
}

void QEnvVoice::setQuality(float _quality)
{
    quality = _quality;
}

