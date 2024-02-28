/*
  ==============================================================================

	WaveSim.cpp
	Created: 23 April 2021
	Author:  Carlos Davey

  ==============================================================================
*/

#pragma once

#define WaveSim_cpp
#define _USE_MATH_DEFINES

#include <cmath>
#include "WaveSim.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <array>
//#include <vector>
#include <tuple>


void WaveSim::setUp()
{
	setArea();
	setc();
	setk();
	seth();
	setN();
	reseth();
	resetc();
	setCoeff();
	setStateVars();
	setInput();
	
}

void WaveSim::setArea()
{
	area = pow(radius, 2) * M_PI;
}

void WaveSim::setc()
{
	float step1 = tension / (rho * area);
	c1 = sqrt(step1);
}

void WaveSim::resetc()
{
	c1 = c2;
}

void WaveSim::setk()
{
	k = 1 / sampleRate;
}

void WaveSim::setN()
{
	N = floor(length / spacing);
	if (N > maxN)
	{
		N = maxN;
	}

}

void WaveSim::seth()
{
	spacing = c1 * k / lambda;
}

void WaveSim::reseth()
{
	spacing = length / N;
}

void WaveSim::setInput()
{
	for (int i = 0; i < N-1; i++)
	{
		// Set values to 0
		u1[i] = 0;

		// Locate the input position/width
		float x = i * spacing;
		float dist = abs(x - inputLoc);

		// Generate raised cosine in input position over input width
		if (dist <= inputWidth)
		{
			u1[i] = 0.5 * inputAmp * (1 + cos(M_PI * dist / inputWidth));
		}
	}
}

void WaveSim::setCoeff()
{
	float Dxx1 = -2 / (pow(spacing, 2));
	std::cout << Dxx1 << "\n";
	float Dxx2 = 1 / (pow(spacing, 2));
	B1 = 2 + (pow(c1, 2) * pow(k, 2) * Dxx1);
	B2 = (pow(c1, 2) * pow(k, 2) * Dxx2);

}

float WaveSim::getLeft()
{
	return yl;
}

float WaveSim::getRight()
{
	return yr;
}

void WaveSim::setStateVars()
{
	u1 = new double[N-1];
	u2 = new double[N-1];
	u = new double[N-1];
	std::fill(u1, u1 + N-1, 0.0f);
	std::fill(u2, u2 + N-1, 0.0f);
	std::fill(u, u + N-1, 0.0f);
}

void WaveSim::process()
{

	// Iterates over each segment of the string
	for (int n = 1; n < N-2; n++)
	{
		// Calculates scheme update from unrolled sparse matrix multiplications
		u[n] = (B1 * u1[n]) + (B2 * u1[n - 1]) + (B2 * u1[n + 1]) - u2[n];
	}
	

	// Reads the output from a specific segment of string
	yl = u[1];
	yr = u[N-4];
	
	// Updates state arrays
	dummyPtr = u2; // dummy pointer equals address stored in u2
	u2 = u1;       // u2 now equals the address of u1, but dummyPtr is still the old address of u2
	u1 = u;        // u1 now equals the address of u, but u2 still equals the old address of u1
	u = dummyPtr;  // u equals the address that u2 used to point to at the start

}

void WaveSim::printAll()
{
	printf("Sample Rate,			SR		: %.12f \n", sampleRate);
	printf("String Length,			L		: %.12f \n", length);
	printf("String Tension,			T		: %.12f \n", tension);
	printf("Initial Wavespeed,		c1		: %.12f \n", c1);
	printf("Adjusted Wavespeed,		c2		: %.12f \n", c2);
	printf("Grid Spacing,			h		: %.12f \n", spacing);
	printf("Input Location,			xi		: %.12f \n", inputLoc);
	printf("Input Width,			width	: %.12f \n", inputWidth);
	printf("Input Amplitude,		amp		: %.12f \n", inputAmp);
	printf("Nominal Courant Number,	lambda	: %.12f \n", lambda);
	printf("Area of string,			A		: %.12f \n", area);
	printf("Density of string,		rho		: %.12f \n", rho);
	printf("Sample Period,			k		: %.12f \n", k);
	printf("Number of Segments,		N		: %d \n", N);
	printf("Scheme Coeffcient 1,	B1		: %.12f \n", B1);
	printf("Scheme Coeffcient 2,	B2		: %.12f \n", B2);
}

void WaveSim::checkInput()
{
	for (int i = 0; i < N-1; i++)
	{
		printf("%.5f \n", u1[i]);
	}
	
}

void WaveSim::setc2(float _c2)
{
	c2 = _c2;
}

void WaveSim::setInputLoc(float _inputLoc)
{
	inputLoc = _inputLoc;
}

void WaveSim::setWidth(float _width)
{
	inputWidth = _width;
}

void WaveSim::resetStates(int numPointsToClear)
{
	std::fill(u1, u1 + numPointsToClear, 0.0f);
	std::fill(u2, u2 + numPointsToClear, 0.0f);
	std::fill(u, u + numPointsToClear, 0.0f);
}

void WaveSim::reset()
{
	setArea();
	setc();
	setk();
	seth();
	setN();
	reseth();
	resetc();
	setCoeff();
	resetStates(this->N);
	setInput();
}

void WaveSim::setLambda(float _lambda)
{
	lambda = _lambda;
}