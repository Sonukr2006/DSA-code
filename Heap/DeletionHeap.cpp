#include<iostream>
#include<vector>
using namespace std;

class Heap {
    public:
    vector<int> arr;
    int size;
    Heap(){
        size = 0;
        arr.reserve(100);
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parentIndex = index / 2;
            if(arr[parentIndex] < arr[index]){
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void deleteMax(){
        if(size == 0){
            cout << "Heap is empty." << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int index = 1;
        while(index < size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int maxIndex = index;
            if(leftChild <= size && arr[leftChild] > arr[maxIndex]){
                maxIndex = leftChild;
            }
            if(rightChild <= size && arr[rightChild] > arr[maxIndex]){
                maxIndex = rightChild;
            }
            if(maxIndex == index){
                break;
            }
            swap(arr[index], arr[maxIndex]);
            index = maxIndex;
        }
    }

    void printHeap(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    h.insert(50);
    h.insert(49);
    h.insert(48);
    h.insert(49);
    h.insert(60);

    h.printHeap();
    h.deleteMax();
    h.printHeap();
    return 0;
}
