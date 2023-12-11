
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

int main()
{
    int i=0;
    for (  ;  ;  ){
        cout << i << endl;
        i++;
        if (i >= 10){
            break;
        }
    }
    // int x = 10;
    // int* address_of_x = &x;
    // cout << address_of_x << endl;
    // int* i = address_of_x - 1;
    // for( ; *i<=10; *i += 1)
    // {
    //     cout << "i = " << i << endl;
    //     *(address_of_x + i) = *(address_of_x + i - 1)*2;
    //     cout << "i = " << i << endl;
    //     cout << *(address_of_x + i) << endl;
    // }
    return 0;
}
