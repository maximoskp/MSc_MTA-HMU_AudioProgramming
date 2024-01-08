#include<iostream>
#include<math.h>

using namespace std;

class SignalGen{
    public:
        SignalGen();
        void make_sine_samples(float amp, float freq, int num_samples, float sr, float* x);
        float get_sine_value_at_time(float amp, float freq, float t);
};