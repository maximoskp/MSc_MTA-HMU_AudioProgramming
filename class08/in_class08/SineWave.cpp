#include"SineWave.h"
#include"math.h"

// constructors
SineWave::SineWave(){
    frequency = 440.f;
    amplitude = 1.f;
    sample_rate = 44100.f;
    make_sine();
}
SineWave::SineWave(float f){
    frequency = f;
    amplitude = 1.f;
    sample_rate = 44100.f;
    make_sine();
}
SineWave::SineWave(float f, float a){
    frequency = f;
    amplitude = a;
    sample_rate = 44100.f;
    make_sine();
}
SineWave::SineWave(float f, float a, float sr){
    frequency = f;
    amplitude = a;
    sample_rate = sr;
    make_sine();
}
// getters
float SineWave::get_frequency(){
    return frequency;
}
float SineWave::get_amplitude(){
    return amplitude;
}
float SineWave::get_sample_rate(){
    return sample_rate;
}
float SineWave::get_signal_at_sample_index(int i){
    return s[i];
}
// setters
void SineWave::set_frequency(float f){
    frequency = f;
    make_sine();
}
// misc function
void SineWave::make_sine(){
    for(int i=0; i<1000; i++){
        s[i] = amplitude*sinf( 2*M_PI*frequency*((float)i)/sample_rate );
    }
}