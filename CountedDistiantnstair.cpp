#include<iostream>
using namespace std;

int countDistiantNStair(int nStair){
    int n = nStair;
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int ans = countDistiantNStair(n-1) + countDistiantNStair(n-2);
    return ans;
    
    
}

int main(){
    int nstair = 5;

    cout<< countDistiantNStair(nstair);

}