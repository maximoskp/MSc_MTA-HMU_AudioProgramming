/*
  ==============================================================================

    SineClass.h
    Created: 12 Dec 2022 8:04:41pm
    Author:  Maximos Kaliakatsos-Papakostas

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SineClass{
public:
    SineClass();
    SineClass(float sr, float f, float a);
    ~SineClass();
    
    // setters
    void set_amplitude(float a);
    void set_frequency(float f);
    void set_sample_rate(float sr);
    
    // getters
    float get_next_sample();
private:
    // generator variables
    float amplitude;
    float frequency;
    // math constants
    float pi = 3.14159265358979323846; // not given by a common library
    // state variables
    float sample_rate;
    // unsigned int total_samples = 0; // we don't count samples any more
    float current_angle = 0.0; // we count angle difference!
};
