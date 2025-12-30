#include<iostream>
using namespace std;
#define PI 3.14
#define PRINT(x) cout << "Value is: "<<x<<endl 
int main(){
    int n=5;
    cout << PI<<endl;
    cout << __LINE__ << " at Current Line"<<endl;
    cout << __FILE__ << " Current file"<<endl;
    cout << __DATE__ << " Compiled Date" << endl;
    PRINT(n);

    return 0;
    
}