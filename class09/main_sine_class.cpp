
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include"SignalGen.h"

using namespace std;

int main()
{
    SignalGen s = SignalGen();
    // float y[1024];
    // s.make_sine_samples(0.7f, 441.f, 1024, 44100, y);
    // for (int i=0; i<101; i++){
    //     cout << y[i] << endl;
    // }
    float sample_rate = 44100.f;
    for (int i=0; i<101; i++){
        float y = s.get_sine_value_at_time(0.7f, 441.f, (float)i/sample_rate);
        cout << y << endl;
    }
    return 0;
}
