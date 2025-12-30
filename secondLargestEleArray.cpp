#include<iostream>
#include<vector>
using namespace std;
int getSecondele(vector<int> arr){
    int largestEle = -1;
    int secondEle = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largestEle)        
        {
            secondEle = largestEle;
            largestEle = arr[i];
        }else if (arr[i] < largestEle && arr[i] > secondEle)
        {
            secondEle = arr[i];
        }
        
        
        
    }
    return secondEle;
    
}
int main(){
    vector<int> arr = {422,34,2,445,67,54,87,67};
    cout << "Sec-Ele: " << getSecondele(arr) << endl;
    return 0;
}