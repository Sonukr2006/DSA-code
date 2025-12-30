#include<iostream>
#include"forClass.cpp"
using namespace std;
int main(){
    Hero h1;
    cout << sizeof(h1)<< endl;
    // size 408
    /* 
    name[100]  = 400 bytes
    health     =   1 byte
    padding    =   3 bytes
    level      =   4 bytes
    ----------------------
    Total      = 408 bytes ✅
    */
}