
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    float frequency = 1.;
    int sample_rate = 100.;
    for(int i=0; i<sample_rate; i++)
    {
        cout << sinf( 2.*M_PI*frequency*i/sample_rate ) << endl;
    }
    
    return 0;
}
