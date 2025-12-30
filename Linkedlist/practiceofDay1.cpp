#include<iostream>
using namespace std;

class Node{

    public:
    int number; 
    Node* next;


    Node(int data){
        this->number = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->number;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data " << number <<endl;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &Tail, int position, int data){
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;   
    }

    if(temp->next == NULL){
        insertAtTail(Tail, data);
        return;
    }

    Node* nodeToAdd = new Node(data);
    nodeToAdd->next = temp->next;
    temp->next = nodeToAdd;
    
    
}

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;

        head = head->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* currNode = head;
        Node* prevNode = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prevNode = currNode;
            currNode = currNode->next;
            cnt++;
        }
        prevNode->next = currNode->next;
        if (currNode->next == NULL)
        {
            tail = prevNode;
        }
        currNode->next = NULL;
        delete currNode;
        
        
    }
}

int main(){
    
    Node* node1 = new Node(10);
    Node* Head = node1;
    Node* Tail = node1;
    cout << Head->number << endl;
    
    insertAtHead(Head, 12);
    insertAtHead(Head, 14);
    insertAtTail(Tail, 16);

    insertAtPosition(Head,Tail,1,20);
    // cout << Tail->number << endl;

    deleteNode(Head, Tail,2);
    print(Head);

    
    
    
    return 0; 


}