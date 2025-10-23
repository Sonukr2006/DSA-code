#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &arr){
    for (int i = 0; i < arr.size()-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[i] > arr[j]){
                swap(arr[minIndex], arr[j]);
            }
        }
        
    }
    for (int val : arr)
    {
        cout << val << " " ;
    }
    cout<<endl;  
}
int main(){
    //For Array Ele Input
    int n;
    cout << "Enter Your Array Size: ";
    cin>> n;
    vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter Your Val : ";
        cin >> val;
        arr.push_back(val);   
    }
    selectionSort(arr);
    return 0;
}