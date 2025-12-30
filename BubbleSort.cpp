#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {5,55,95,1005,56,84,2,4};
    for (int i = 1; i < arr.size(); i++) //let round = 1 -> 2 -> 3...-> n
    {
        for (int j = 0; j < arr.size()-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }   
        }    
    }
    for (int &val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    
    

    return 0;
}