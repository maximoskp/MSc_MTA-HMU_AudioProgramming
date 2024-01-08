#include"SignalGen.h"

SignalGen::SignalGen(){}

void SignalGen::make_sine_samples(float amp, float freq, int num_samples, float sr, float* x){
    for(int i=0; i<num_samples; i++){
        x[i] = amp*sinf(2.f*M_PI*freq*( (float)i/sr ));
    }
}

float SignalGen::get_sine_value_at_time(float amp, float freq, float t){
    return amp*sinf(2.f*M_PI*freq*t);
}