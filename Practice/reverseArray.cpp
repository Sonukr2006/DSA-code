#include<iostream>
using namespace std;

int main(){
    int arr[5] = {2,3,4,5,6};
    int n = sizeof(arr)/4;

    // sizeof => size * (type of array) size(byte)

    for (int i = 0; i < n/2; i++)
    {
        swap(arr[i], arr[n-i-1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
}