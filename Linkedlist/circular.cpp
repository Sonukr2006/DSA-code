#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data:" << value ;
    }
};
void print(Node* tail){
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    
    Node* temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;  
}

void insertNode(Node* &tail, int data, int element){
    if (tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode ->next = newNode;
    }
    else{

        Node* curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;    
    }
    
}

bool checkList(Node* tail){
    if(tail == NULL){
        return true;
    }

    Node* temp = tail->next;
    while (temp != NULL && temp != tail)
    {
        temp = temp->next;
    }

    if (temp == tail)
    {
        return true;
    }
    return false;
    
    
}


bool detectLoop(Node* &head){
    if (head == NULL)
    {
        return false;
    }
    map<Node*, bool> visited;    
    Node* temp = head;
    while (temp != NULL)
    {
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}



int main(){
    Node* tail = NULL;
    insertNode(tail, 4, 5);
    print(tail);
    if (checkList(tail))
    {
        cout << "List is circular " << endl;
    }
    else{
        cout << "List is not circular" << endl;
    }

    if (detectLoop(tail))
    {
        cout << "Loop Detect" << endl;
    }
    else{
        cout << "Loop Not Found" << endl;
    }
    
    

    return 0;
}