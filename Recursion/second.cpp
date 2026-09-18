#include<iostream>
using namespace std;

int fun(int n){
    if (n == 0)
    {
        return 0;
    }
    int sum = n+1;
    fun(n-1);

    return sum;
    
}

void twotable(int n, int num){
    if(n == 0)
        return;

        
        cout << num*2 << endl;
        num += 1;
    twotable(n-1, num);
}

int main() {
    cout << fun(10);
}