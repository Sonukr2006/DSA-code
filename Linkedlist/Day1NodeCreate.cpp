#include<iostream>
using namespace std;

class Node {
public:

    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this ->data = data;
        this ->next = NULL;
    }

};

void InsertedatHead(Node* &Head, int data){
    Node* temp = new Node(data);
    temp -> next = Head;
    Head = temp;
}

void printList (Node* &Head){
    Node* temp = Head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    
}

void insertatTail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail ->next = temp;
    tail = temp;
}

int main(){

    Node* Node1 = new Node(10);

    // cout << Node1->  data << endl;
    // cout << Node1 -> next << endl;

    Node* head = Node1;
    Node* tail = Node1;
    printList(head);

   insertatTail(tail, 12);
    printList(head);

    insertatTail(tail, 15);
    printList(head);

    insertatTail(tail, 16);
    printList(head);

    insertatTail(tail, 17);
    printList(head);

    insertatTail(tail, 11);
    printList(head);

    return 0;
}