#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;

    public:

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
        cout << "Stack is created of this Size : " << size << endl;
    }

    void push(int ele){
        if(size - top > 1){
            top++;
            arr[top] = ele;
            cout << "Push Element Successfully Completed." << ele << endl;
        }
        else{
            cout << "Stack is OverFlow" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
            cout << "Pop Element Successfully Completed." << endl;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            return -1;
        }
    };
    bool isEmpty(){
        if (top == -1)
        {
            return 1;
        }
        
    }

    int length(){
        return (this->size);
    }
    void print() {
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }
};


int main(){
    Stack st(5);

    st.push(88);
    st.push(55);
    st.push(12);

    st.print();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;


}