#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n = 40;
    int count = 0;
    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false;
    
    for (int i = 2; i < prime.size(); i++)
    {
        if(prime[i]){
            count++;
            cout << "Prime no. : " << i << endl;


            for (int j = 2*i; j < prime.size(); j=j+i)
            {
                prime[j] = 0;
            }
            
        }
    }
    cout <<"No of prime no btw 0 to 40 : "<< count << " "<<endl;
    
    return 0;
}