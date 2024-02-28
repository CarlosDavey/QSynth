/*
  ==============================================================================

    QEnveloper.h
    Created: 23 April 2021
    Author:  Carlos Davey

  ==============================================================================
*/

#pragma once

#define QEnveloper_h
#include <JuceHeader.h>
#include "WaveSim.h"

// ===========================

/// <summary>
/// Defines a Class for the enveloper
/// </summary>
class QEnvSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int) override { return true; }
    //--------------------------------------------------------------------------
    bool appliesToChannel(int) override { return true; }
};


// ===========================
/// <summary>
/// Defines the behaviour of the QEnveloper voice, which can be called any number of times to generate a polyphonic output
/// </summary>
class QEnvVoice : public juce::SynthesiserVoice
{
public:
    QEnvVoice() {}

    /// <summary>
    /// Initialise the voice, by setting up the ADSR envelope values for both the processed and carrier sounds
    /// </summary>
    /// <param name="sampleRate"></param>
    void init(float sampleRate);
    //---------------------------------------------------------

    /// <summary>
    /// Allows update of release value from UI
    /// </summary>
    /// <param name="_release"></param>
    void setRelease(float _release);
    //---------------------------------------------------------

    /// <summary>
    /// Allows update of wavespeed value from UI
    /// </summary>
    /// <param name="_waveSpeed"></param>
    void setWaveSpeed(float _waveSpeed);
    //---------------------------------------------------------
    
    /// <summary>
    /// Allows update of input location from UI
    /// </summary>
    /// <param name="_inputLoc"></param>
    void setInputLoc(float _inputLoc);
    //---------------------------------------------------------

    /// <summary>
    /// Allows update of pulsewidth from UI
    /// </summary>
    /// <param name="_width"></param>
    void setWidth(float _width);
    //---------------------------------------------------------

    /// <summary>
    /// Defines behaviour of the enveloper when a MIDI note is detected by the noteOn message
    /// </summary>
    /// <param name=""></param>
    /// <param name=""></param>
    /// <param name=""></param>
    /// <param name=""></param>
    void startNote(int /*midiNoteNumber*/, float /*velocity*/, juce::SynthesiserSound*, int /*currentPitchWheelPosition*/) override;
    //---------------------------------------------------------

    /// <summary>
    /// Define behaviour of the enveloper when a MIDI note is stopped, detected by noteOff message
    /// </summary>
    /// <param name=""></param>
    /// <param name=""></param>
    void stopNote(float /*velocity*/, bool /*allowTailOff*/) override;
    //---------------------------------------------------------

    /// <summary>
    /// MAIN DSP BLOCK: If the sound that the voice is playing finishes during the course of this rendered block, it must call clearCurrentNote(), to tell the synthesiser that it has finished
    /// </summary>
    /// <param name="outputBuffer">pointer to output</param>
    /// <param name="startSample">position of first sample in buffer</param>
    /// <param name="numSamples">number of smaples in output buffer</param>
    void renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
    //---------------------------------------------------------

    /// <summary>
    /// Define if the voice is able to play sound
    /// </summary>
    /// <param name="sound"></param>
    /// <returns></returns>
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    //---------------------------------------------------------

    /// <summary>
    /// Allow the address of a buffer to be passed into the voice, so the input audio can be accessed
    /// </summary>
    /// <param name="inputCopy">Copy of the input audio buffer</param>
    void setInputBuffer(juce::AudioBuffer<float>& inputCopy);
    //---------------------------------------------------------

    /// <summary>
    /// Allows the update of gain values from the UI
    /// </summary>
    /// <param name="_inputGain"></param>
    /// <param name="_outputGain"></param>
    void setGain(float _inputGain, float _outputGain);
    //---------------------------------------------------------

    /// <summary>
    /// Allows the update of the maximum N value from the UI
    /// </summary>
    /// <param name="quality"></param>
    void setQuality(float _quality);
    //---------------------------------------------------------

    /// <summary>
    /// Unused pitch wheel method
    /// </summary>
    /// <param name=""></param>
    void pitchWheelMoved(int) override {}
    //---------------------------------------------------------

    /// <summary>
    /// Unused controller method
    /// </summary>
    /// <param name=""></param>
    /// <param name=""></param>
    void controllerMoved(int, int) override {}
    //---------------------------------------------------------

private:
    
    // Should the voice be playing?
    bool playing = false;

    // Should the voice be ending?
    bool ending = false;

    // Instantiate the string simulation
    WaveSim string;

    // Instatiate the processed and carrier envelopes
    juce::ADSR env;
    juce::ADSR envCarrier;

    // Define and default UI values
    float releaseVal = 10.0f;
    float waveSpeedVal = 0.5f;
    float inputLocVal = 0.1f;
    float dryWet = 0.5f;
    float gain = 1.0f;
    float width = 0.01f;
    float quality = 1.0f;

    // Instantiate an audio buffer pointer to store the input audio
    juce::AudioBuffer<float>* inputBuffer;

};