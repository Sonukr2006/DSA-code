#include <iostream>
#include <vector>
using namespace std;

class Heap {
    public:
    vector<int> arr; // Initialize a vector of size 100
    int size;
    Heap(){
        size = 0;
        arr.reserve(100); // Reserve space for 100 elements
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
    return 0;
}
