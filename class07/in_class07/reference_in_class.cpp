
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

int main()
{
    long x = 5;
    cout << "x increased by 1: " << x + 1 << endl;
    // show memory location of x
    cout << "memory location of x:                " << &x << endl;
    cout << "memory location of x increased by 1: " << &x + 1 << endl;
    cout << "sizeof(x): " << sizeof(x) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "content of next RAM location of x: " << *(&x+1) << endl;
    // &: θα το διαβάζουμε σαν "διεύθυνση". Πχ &x το διαβάζουμε "διεύθυνση x".
    // *: (όταν δεν αρχικοποιεί pointer) θα το διαβάζουμε σαν "περιεχόμενο".
    long* address_of_x = &x;
    cout << "address_of_x: " << address_of_x << endl;
    for ( int i=1; i<=5; i += 2 ){
        cout << address_of_x + i << endl;
        *(address_of_x + i) = 10;
    }
    // cout << "address_of_x * 2" << address_of_x*2 << endl; // error
    return 0;
}
