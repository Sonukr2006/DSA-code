#include<iostream>
#include<vector>
using namespace std;

void bubble(vector<int>& arr, int n){
    if(n == 0){
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (arr[j] > arr[j+1])
        {
            swap(arr[j], arr[j+1]);
        }   
    }
    bubble(arr, n-1);
    

}
int main(){
    vector<int> arr = {5,55,95,1005,56,84,2,4};

    bubble(arr, arr.size()-1);
    
    for (int &val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    
    

    return 0;
}