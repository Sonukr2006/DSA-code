#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int s;
    int frontt;
    int rear;
    public:
    Queue(){
        s = 10001;
        arr = new int[s];
        frontt = 0;
        rear = 0;
    }
public:
    bool isEmpty(){
        if(rear == frontt)
            return 1;
        else
            return 0;
    }
    void inqueue(int data){
        if (rear != s)
            arr[rear] = data;
            rear++;
    }
    int dequeue (){
        if (isEmpty())
            return -1;
        int data = arr[frontt];
        frontt++;
        return data;
    }
    int front(){
        if (frontt == rear)
            return -1;
        return arr[frontt];
    }
    int size(){
        return s-rear;
    }
};



int main(){

    Queue q;
    q.inqueue(5);

    cout << q.front();


    return 0;
}