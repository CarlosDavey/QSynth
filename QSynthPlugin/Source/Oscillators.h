// Oscillators.h

#pragma once

#define Oscillators_h

#include <cmath>
#include <vector> 
#include "Phasors.h"
//PARENT PHASOR CLASS

//=======================================


class SinOsc : public Phasor
{
public: 

	void setup(float _sampleRate, float _frequency)
	{
		setSampleRate(_sampleRate);
		setFrequency(_frequency);
	}

	float output(float p) override
	{
		return std::sin(p * 2.0 * 3.14159);
	}
};

class SquareOsc : public Phasor
{
public:

	void setup(float _sampleRate, float _frequency, float _pulsewidth)
	{
		setSampleRate(_sampleRate);
		setFrequency(_frequency);
		setPulseWidth(_pulsewidth);
	}

	float output(float p) override
	{
		float outVal = 0.5;
		if (p > getPulseWidth())
			outVal = -0.5;
		return outVal;
	}

	void setPulseWidth(float pw)
	{
	pulsewidth = pw;
	}

	float getPulseWidth()
	{
		return pulsewidth;
	}
		

private:
	float pulsewidth = 0.0;
};

class SawOsc : public Phasor
{
public:

	void setup(float _sampleRate, float _frequency)
	{
		setSampleRate(_sampleRate);
		setFrequency(_frequency);
	}

	float output(float p) override
	{
		float bphase = (2 * p) - 1;
		float sq = pow(bphase, 2);
		float dsq = sq * ((1 - getz1())*(1 + getz1()))/2;

		setz1(sq);

		return getc() * dsq;
	}
};

