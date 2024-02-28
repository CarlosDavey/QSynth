/*
  ==============================================================================

	WaveSim.h
	Created: 23 April 2021
	Author:  Carlos Davey

  ==============================================================================
*/

#pragma once

#define WaveSim_h
#include <cmath>
#include <tuple>


/// <summary>
///  The string simulator class
/// </summary>

class WaveSim
{
public:

	/// <summary>
	/// Setup required for the string class to be initialised
	/// 
	/// Run this method FIRST before any others 
	/// </summary>
	void setUp();
	//---------------------------------------------------------

	/// <summary>
	/// Set string area
	/// </summary>
	void setArea();
	//---------------------------------------------------------

	/// <summary>
	/// Calculate and set the wavespeed, c
	/// </summary>
	void setc();
	//---------------------------------------------------------

	/// <summary>
	/// Set the value of k, the timestep
	/// </summary>
	void setk();
	//---------------------------------------------------------

	/// <summary>
	/// Calculate and set grid spacing, h
	/// </summary>
	void seth();
	//---------------------------------------------------------

	/// <summary>
	/// Set N, the number of segments of the string
	/// </summary>
	void setN();
	//---------------------------------------------------------

	/// <summary>
	/// Recalculate and set h based on N
	/// </summary>
	void reseth();
	//---------------------------------------------------------

	
	/// <summary>
	/// Set the wavespeed to a manually input value
	/// </summary>
	void resetc();
	//---------------------------------------------------------
	
	/// <summary>
	/// Set scheme coefficients
	/// </summary>
	void setCoeff();
	//---------------------------------------------------------

	/// <summary>
	/// Set up the state variable arrays
	/// </summary>
	void setStateVars();
	//---------------------------------------------------------

	/// <summary>
	/// Initialise the input vector
	/// </summary>
	void setInput();
	//---------------------------------------------------------
	

	/// <summary>
	/// Run the loop
	/// 
	/// Run this method AFTER setup
	/// </summary>
	void process();
	//---------------------------------------------------------

	/// <summary>
	/// Print all stored variables
	/// </summary>
	void printAll();
	//---------------------------------------------------------

	/// <summary>
	/// Print input vector
	/// </summary>
	void checkInput();
	//---------------------------------------------------------

	/// <summary>
	/// Getter function for the left channel
	/// </summary>
	/// <returns>
	/// Left channel sample
	/// </returns>
	float getLeft();
	//---------------------------------------------------------

	/// <summary>
	/// Getter function for the right channel
	/// </summary>
	/// <returns>
	/// Right channel sample
	/// </returns>
	float getRight();
	//---------------------------------------------------------

	/// <summary>
	/// Set Wavespeed Value
	/// </summary>
	/// <param name="_c2"></param>
	void setc2(float _c2);
	//---------------------------------------------------------

	/// <summary>
	/// Set Input Location
	/// </summary>
	/// <param name="_inputLoc"></param>
	void setInputLoc(float _inputLoc);
	//---------------------------------------------------------

	/// <summary>
	/// Set new Nominal Courant Number
	/// </summary>
	/// <param name="_lambda"></param>
	void setWidth(float _width);
	//---------------------------------------------------------

	/// <summary>
	/// Instatiate state vectors with zeros
	/// </summary>
	void resetStates(int numPointsToClear);
	//---------------------------------------------------------

	/// <summary>
	/// Performs same function as setup(), just without memory allocation
	/// </summary>
	void reset();
	//---------------------------------------------------------

	/// <summary>
	/// Set the Nominal Courant number which defines the maximum N value
	/// </summary>
	void setLambda(float _lambda);
	//---------------------------------------------------------


private:

	/// <summary>
	/// GLOBAL PARAMETERS
	/// </summary>
	double sampleRate = 44100;			// Operating Sample Rate (Hz)
	double length = 1;					// Length of String	(m)
	double tension = 60;				// Tension of String (N)
	double c1;							// Calculated wavespeed from Physical Params
	double c2 = 0.5;					// User defined wavespeed
	double spacing = 0.002;				// Grid spacing
	double inputLoc = 0.1;				// Location of input
	double inputWidth = 0.01;			// Width of input
	double inputAmp = 0.01;				// Amplitude of input
	double lambda = 1;					// Nominal Courant number 
	double radius = 0.0005;				// Radius of string
	double rho = 10000;					// Density of string

	static constexpr const int maxN = 504; // Change this and gauge perfomance


	/// <summary>
	/// DERIVED PARAMETERS
	/// </summary>
	double k;							// Sampling Period
	double area;						// Area of string
	int N;								// Number of spacings along length


	/// <summary>
	/// STATE AND OUTPUT VECTORS
	/// </summary>
	double* u1;							// Current state array
	double* u2;							// Previous state array
	double* u;							// Next state array
	double yl = 0;						// Output left channel
	double yr = 0;						// Output right channel
	double* dummyPtr;					// Dummy Pointer

	/// <summary>
	/// SCHEME COEFFICIENTS
	/// </summary>
	double B1;							// Scheme coefficient 1 (diagonal)
	double B2;							// Scheme coefficient 2 (off-diag)

	
};
