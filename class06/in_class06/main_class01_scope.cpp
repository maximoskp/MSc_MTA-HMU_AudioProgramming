
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
using namespace std;

int x = 5;

int main()
{
    // logical conditions
    // cout << (bool)(1 == 2) << endl;
    // int x = 6; // erases the existing definition of x
    // and creates a new x variable
    // a new scope can preserve the global value of x
    // and create a new x
    {
        int x = 6;
        cout << "within scope x = " << x << endl;
    }
    cout << "global scope x = " << x << endl;
    {
        // since x is not re-difined within this scope,
        // the global value of x is considered 
        x = 6;
        cout << "changing global x within scope x = " << x << endl;
    }
    cout << "global scope x = " << x << endl;
    return 0;
}
