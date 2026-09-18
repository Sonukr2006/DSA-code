#include<iostream>
using namespace std;

class KQueue{
  public:
    int n;
    int k;
    int freeSpot;
    int *front;
    int *rear;
    int *next;
    int *arr;

  KQueue(int n, int qn){
    this->n = n;
    this->k = qn;
    freeSpot = 0;
    front = new int[qn];
    rear = new int[qn];
    for(int i =0; i < qn; i++){
      front[i] = rear[i] = -1;
    }
    next = new int[n];
    for(int i = 0; i < n-1; i++){
      next[i] = i+1;
    }
    next[n-1] = -1;
    arr = new int[n];
  }



  void enqueue(int data, int qn){
    // Overflow Conditions check
    if(freeSpot == -1){
      cout << "Empty List !" << endl;
      return;
    }
    //find first index
    int index = freeSpot;
    // update freeSpot 
    freeSpot = next[index];
    // Checking for first index
    if(front[qn] == -1){
      front[qn-1] = index;
    }else{
      // link curr elemnt to prev element
      next[rear[qn]] = index;
    }
    // update next
    next[index] = -1;
    // update rear
    rear[qn-1] = index;
    // push at right index
    arr[index] = data;
    return;
  }

  int deQueue(int qn){
    if(front[qn-1] == -1){
      cout << "Queue Underflow" << endl;
      return -1;
    }
    // Find index 
    int index = front[qn-1];
    // update the front array
    front[qn-1] = next[index];

    // link with next free space after this index
    next[index] = freeSpot;
    // update curr free space index
    freeSpot = index;

    return arr[index];

  }
};


int main(){

  KQueue nthQue(10, 3);

  nthQue.enqueue(5, 1);
  nthQue.enqueue(8, 2);
  nthQue.enqueue(9, 1);

  cout << "Remove Data : "<< nthQue.deQueue(2) << endl;
  nthQue.enqueue(81, 2);
  cout << nthQue.arr[0] << nthQue.arr[1] << nthQue.arr[2] << endl;


  return 0;
}