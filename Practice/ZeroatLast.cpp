#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &arr){
    int count = 0;
    for (int  i = 0; i < arr.size(); i++)
    {
        if(arr[i] != 0){
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main(){
    vector<int> arr = {3,0,0,2,0};
    solve(arr);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    

    return 0;
}