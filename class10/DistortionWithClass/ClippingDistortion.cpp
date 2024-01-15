/*
  ==============================================================================

    ClippingDistortion.cpp
    Created: 18 Dec 2023 4:55:27pm
    Author:  monog

  ==============================================================================
*/

#include "ClippingDistortion.h"

ClippingDistortion::ClippingDistortion() {
    preamp_value = 4.;
    clip_value = 0.6;
    poweramp_value = 1.3;
}
float ClippingDistortion::process_sample(float s) {
    float d = preamp_value * s;
    if (d > clip_value) {
        d = clip_value;
    }
    else if (d < -clip_value) {
        d = -clip_value;
    }
    return poweramp_value*d;
}

// setters
void ClippingDistortion::set_preamp_value(float x) {
    preamp_value = x;
}
void ClippingDistortion::set_clip_value(float x) {
    clip_value = x;
}
void ClippingDistortion::set_poweramp_value(float x) {
    poweramp_value = x;
}

// getters
float ClippingDistortion::get_preamp_value() {
    return preamp_value;
}
float ClippingDistortion::get_clip_value() {
    return clip_value;
}
float ClippingDistortion::get_poweramp_value() {
    return poweramp_value;
}