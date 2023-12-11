#include<iostream>

using namespace std;

void add_arrays( int* z, int* x, int* y, int number_of_elements ){
    for( int i=0 ; i<number_of_elements ; i++ ){
        z[i] = x[i] + y[i];
    }
    return;
}

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
    // do the addition in a function
    add_arrays(z, x, y, 10);
    for (int i=0; i<10; i++){
        // z[i] = x[i] + y[i];
        cout << "z[" << i << "] = " << z[i] << endl;
    }
    
    return 0;
}
