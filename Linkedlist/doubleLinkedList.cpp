#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* pre;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }

    ~Node(){
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data " << data <<endl;
        
    }

};

void print(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

int getLength(Node* head){
    int length = 0;

    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
    
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if (head==NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    
}

void insertAtTail(Node* &head, Node* &tail, int data){
    
    if (tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
    
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if (position == 1)
    {
        insertAtHead(head,tail, data);
        return ;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1)
    {
        temp =  temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *insertNode = new Node(data);

    insertNode->next = temp->next;
    temp->next->pre = insertNode;
    temp->next = insertNode;
    insertNode->pre = temp;
    
}

void deleteNode(Node* &head, Node* &tail, int position){
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next->pre = NULL;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* currNode = head;
        Node* preNode = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            preNode = currNode;
            currNode = currNode->next;
            cnt++;
        }

        currNode->pre = NULL;
        preNode->next = currNode->next;
        if(currNode->next == NULL){
            tail = preNode;
        }
        currNode->next = NULL;

        delete currNode;

        
    }

    
}

int main(){
    Node* Head = NULL;
    Node* Tail = NULL;
    insertAtHead(Head,Tail, 26);
    insertAtHead(Head,Tail, 45);
    insertAtHead(Head,Tail, 01);

    insertAtTail(Head,Tail, 33);
    
    print(Head);
    insertAtPosition(Head, Tail, 3, 37);
    print(Head);

    deleteNode(Head, Tail,2);
    // cout<< Tail->data << endl;
    print(Head);

    cout << getLength(Head) << endl;

    return 0;
}