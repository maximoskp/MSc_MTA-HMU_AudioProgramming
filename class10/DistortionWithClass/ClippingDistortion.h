/*
  ==============================================================================

    ClippingDistortion.h
    Created: 18 Dec 2023 4:55:27pm
    Author:  monog

  ==============================================================================
*/

#pragma once

#include<iostream>

using namespace std;

class ClippingDistortion {
public:
    ClippingDistortion();
    float process_sample(float s);

    // setters
    void set_preamp_value(float x);
    void set_clip_value(float x);
    void set_poweramp_value(float x);

    // getters
    float get_preamp_value();
    float get_clip_value();
    float get_poweramp_value();

private:
    float preamp_value;
    float clip_value;
    float poweramp_value;
};