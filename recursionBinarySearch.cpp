#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int>& arr,int target, int s, int e){
    int mid = s + (e -s)/2;
    if(arr[mid] == target){
        return 1;
    }
    if (e>s)
    {
        return 0;
    }
    
    

    if (arr[mid] > target)
    {
        return binarySearch(arr, target,0,mid-1);
    }else{
        return binarySearch(arr,target,mid+1,e);
    }
    return 0;
    
}
int main(){
    vector<int> arr = {2, 4, 5, 55, 56, 84, 95, 1005 };
    int target = 2200;

    if (    binarySearch(arr, target,0,arr.size()-1))
    {               
        cout << "Target Found : " << target << endl;
    }else{
        cout << "Target not Found : " << target << endl;
    }
    


    return 0;
}