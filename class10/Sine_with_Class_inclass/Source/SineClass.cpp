/*
  ==============================================================================

    SineClass.cpp
    Created: 12 Dec 2022 8:04:41pm
    Author:  Maximos Kaliakatsos-Papakostas

  ==============================================================================
*/

#include "SineClass.h"

SineClass::SineClass(){
    frequency = 200.;
    amplitude = 0.8;
    sample_rate = 44100.;
}
SineClass::SineClass(float sr, float f, float a){
    sample_rate = sr;
    frequency = f;
    amplitude = a;
}
SineClass::~SineClass(){
    
}

// setters
void SineClass::set_amplitude(float a){
    amplitude = a;
}
void SineClass::set_frequency(float f){
    frequency = f;
}
void SineClass::set_sample_rate(float sr){
    sample_rate = sr;
}

// getters
float SineClass::get_next_sample(){
    float next_sample = amplitude * std::sin( current_angle );
    current_angle += 2. * pi * frequency* 1. / sample_rate;
    // since we don't have infinite precision in pi, we need to keep
    // the angle value within one turn of the unit circle
    while (current_angle > 2. * pi) {
        current_angle -= 2. * pi;
    }
    return next_sample;
}
