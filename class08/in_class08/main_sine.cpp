
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include"SineWave.h"

using namespace std;

int main()
{
    SineWave s = SineWave(220.f, 0.7);
    cout << "frequency: " << s.get_frequency() << endl;
    cout << "amplitude: " << s.get_amplitude() << endl;
    cout << "sample rate: " << s.get_sample_rate() << endl;
    for(int i=0; i<1000; i++){
        cout << s.get_signal_at_sample_index(i) << endl;
    }
    s.set_frequency(220.f);
    return 0;
}
