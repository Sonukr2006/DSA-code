#include<iostream>
using namespace std;

int main(){


    int i = 5;
    int *p = &i;
    

    cout << p << endl;
    cout << *p << endl;

    *p--;

    cout << p << endl;




    return 0;
}