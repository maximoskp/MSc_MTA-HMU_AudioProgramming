
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include"SineWave.h"

using namespace std;

int main()
{
    SineWave s = SineWave(220.f, 0.7);
    SineWave* s1 = new SineWave(330.f, 0.9);
    cout << "frequency: " << s.get_frequency() << endl;
    cout << "amplitude: " << s.get_amplitude() << endl;
    cout << "sample rate: " << s.get_sample_rate() << endl;
    for(int i=0; i<1000; i++){
        cout << s.get_signal_at_sample_index(i) << endl;
    }
    s.set_frequency(220.f);
    cout << "size of s: " << sizeof(s) << endl;
    cout << "size of s1: " << sizeof(s1) << endl;
    cout << "frequency: " << s1->get_frequency() << endl;
    cout << "amplitude: " << s1->get_amplitude() << endl;
    cout << "sample rate: " << s1->get_sample_rate() << endl;
    for(int i=0; i<1000; i++){
        cout << s1->get_signal_at_sample_index(i) << endl;
    }
    s1->set_frequency(220.f);
    return 0;
}
