#include<iostream>
#include<math.h>

// using namespace std;

int n = 5;
// float x = 3.14;
// double y = 3.14;
float x = 1./3.;
double y = 1./3.;
bool b = true;
char c = 'a';
std::string s = "I am a string";

int main()
{
    std::cout << "Hello world! " + std::string("New message") << std::endl;
    std::cout << "n = " + std::to_string(n) << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "s = " << s << std::endl;
    std::cout << "pi = " << M_PI;
    return 0;
}