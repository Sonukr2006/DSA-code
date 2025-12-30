#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int s, int e){

    int pivot = arr[s];
    int count = 0;

    for (int i = s+1; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
        
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i=s, j=e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (i < pivotIndex && arr[i] <= pivot)
        {
            i++;
        }
        while (j < pivotIndex && arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
     
    }
    
    return pivotIndex;

}

void quickSort(vector<int>& arr, int s, int e){

    // Base case
    if(s >= e)
        return;

    int p = partition(arr, s, e);

    // Left Part
    quickSort(arr, s, p-1);

    // right part
    quickSort(arr, p+1, e); 
}

int main(){

    vector<int> arr = {2,56,54,44,55,35,78,65,2};
    int n =  arr.size()-1;
    quickSort(arr, 0,n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
    

    return 0;
}
