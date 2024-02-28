#pragma once

#define Phasors_h

#include <cmath>
#include <vector> 
//PARENT PHASOR CLASS
class Phasor
{
public:


	// Our parent oscillator class does the key things required for most oscillators:
	// -- Handles phase
	// -- Handles setters and getters for frequency and sample rate

	// update the phase and output the next sample from the oscillator
	float process()
	{
		phase += phaseDelta;

		if (phase > 1.0f)
			phase -= 1.0f;

		return output(phase);
	}

	virtual float output(float p)
	{
		return p;
	}

	void setSampleRate(float SR)
	{
		sampleRate = SR;
	}

	float getSampleRate()
	{
		return sampleRate;
	}

	void setFrequency(float freq)
	{
		frequency = freq;
		setPhaseDelta();
	}

	void setPhaseDelta()
	{
		phaseDelta = frequency / sampleRate;
	}

	float getFrequency()
	{
		return frequency;
	}

	void setz1(float Z1)
	{
		z1 = Z1;
	}

	float getz1()
	{
		return z1;
	}

	float getc()
	{
		return c;
	}

	void setPhase(float phaseadd)
	{
		phase += phaseadd;
	}

private:
	float frequency;
	float sampleRate;
	float phase = 0.0f;
	float phaseDelta;
	float z1 = 0.0f;
	float c = sampleRate / (2 * frequency);

};