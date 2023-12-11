#include<iostream>

class SineWave{
    private:
        float sample_rate;
        float frequency;
        float amplitude;
        float s[1000]; // this array will hold the sinusoidal signal
        // misc function
        void make_sine();
    public:
        SineWave();
        SineWave(float f);
        SineWave(float f, float a);
        SineWave(float f, float a, float sr);
        // getters
        float get_frequency();
        float get_amplitude();
        float get_sample_rate();
        float get_signal_at_sample_index(int i);
        // setters
        void set_frequency(float f);
};