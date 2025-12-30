#include<iostream>
using namespace std;

int reverseNum(int n, int rev = 0){

    if (n == 0) {
        return rev;
    }
    
    int digit = n % 10;
    rev = rev * 10 + digit;
    return reverseNum(n / 10, rev);
}

int main(){
    int n= 412;

    if (reverseNum(n) == n) 
    {
        cout << "Plaindrome no : true" << endl;
    }
    else{
        cout << "Plaindrome no : false" << endl;
    }
    

    return 0;   
}