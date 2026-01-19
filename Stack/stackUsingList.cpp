#include <iostream>
using namespace std;

class List{
public:
    int data;
    List *next;

    List(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{

    public:
    List* head = NULL;
    int s = 0;

    void push(int data){
        List* node = new List(data);
        node->next = head;
        head = node;
        s++;
    }
    int size(){
        return this->s;
    }

    int peek(){
        return head->data;
    }
    int top(){
        return head->data;
    }

    void pop(){
        if (head == NULL)
        {
            cout << " underFlow Condition " << endl;
        }
        
        head = head->next;
    }
};

int main(){

    // Stack st;
    // st.push(5);
    // st.push(45);
    // st.push(85);

    Stack* st = new Stack();
    st->push(5);
    st->push(45);
    st->push(85);

    cout << st->size() << endl;
 
    return 0;
}