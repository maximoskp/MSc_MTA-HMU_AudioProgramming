#include<iostream>

using namespace std;

int main()
{
    int x[10];
    int y[10];
    int z[10];
    // initialize x
    for (int i=0; i<10; i++){
        x[i] = rand() % 10 + 1;
        y[i] = rand() % 10 + 1;
        cout << "x[" << i << "] = " << x[i] << endl;
        cout << "y[" << i << "] = " << y[i] << endl;
    }
    for (int i=0; i<10; i++){
        z[i] = x[i] + y[i];
        cout << "z[" << i << "] = " << z[i] << endl;
    }
    
    return 0;
}
