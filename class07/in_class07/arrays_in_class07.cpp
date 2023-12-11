#include<iostream>

using namespace std;

int main()
{
    int x[5] = {3,5,7,8,9};
    cout << "x[0] = " << x[0] << endl;
    cout << "x[3] = " << x[3] << endl;
    // arrays as pointers
    cout << "x =     " << x << endl;
    cout << "&x[0] = " << &x[0] << endl;
    cout << "&x[1] = " << &x[1] << endl;
    // 
    cout << "*x = " << *x << endl;
    cout << "*(x+3) = " << *(x+3) << endl;
    // 
    int y[10];
    for (int i=0; i<10; i++)
    {
        y[i] = i;
    }
    cout << "y[4] = " << y[4] << " - *(y+4) = " << *(y+4);
    return 0;
}
