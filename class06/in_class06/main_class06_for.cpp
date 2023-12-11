
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
using namespace std;

int main()
{
    // int n = 5;
    // cout << ++n << endl;
    // cout << n++ << endl;
    // for(int i=0; i<=10; i++){
    //     cout << i << endl;
    // }
    int i = 0;
    for( ; ; ){
        cout << ++i << endl;
        if (i >= 10){
            break;
        }
    }
    return 0;
}
