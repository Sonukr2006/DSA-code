#include<iostream>
#include<vector>
using namespace std;


void Selection(vector<int> &arr){
    for (int i = 0; i < arr.size()-1; i++)
    {
        int midIndex = i;  // assume current index is minimum
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] < arr[midIndex])
            {
                midIndex = j;  // update index of smaller element
            }
            
        }
        // swap once after inner loop completes
        swap(arr[i], arr[midIndex]);
        
    }
    for (int val : arr)
    {
        cout << val << " " ;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {5,8,23,9,7,7,5,19};
    cout<< "Sorted Array : ";
    Selection(arr);
    return 0;
}