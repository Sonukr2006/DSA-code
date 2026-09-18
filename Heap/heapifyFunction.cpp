#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int> arr;
    int size;
    public:
    Heap(){
        size = 0;
        arr.push_back(0);
    }
    

    void insert(int val){
        size++;
        int index = size;

        arr.push_back(val);

        while(index > 1){
            int parentNodeIndex = index/2;
            if(arr[parentNodeIndex] < arr[index]){
                swap(arr[parentNodeIndex], arr[index]);
                index = parentNodeIndex;
            }
            else
            {
                break;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

void heapify(vector<int> &arr, int size, int index){
    int leftIndex = index * 2;
    int rightIndex = leftIndex + 1;

    if(leftIndex > size){
        return;
    }

    int largestIndex = leftIndex;

    if(rightIndex <= size && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }

    if(arr[index] >= arr[largestIndex]){
        return;
    }

    swap(arr[index], arr[largestIndex]);
    heapify(arr, size, largestIndex);
}

int main(){

    Heap heap;

    heap.insert(55);
    heap.insert(59);
    heap.insert(53);

    heap.print();

    vector<int> arr = {-1, 0, 53, 55, 52, 50, 46,98};

    for(int i = (arr.size()-1)/2; i > 0; --i){
        heapify(arr, arr.size()-1, i);
    }

    for(int i = 1; i <= arr.size() - 1; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

