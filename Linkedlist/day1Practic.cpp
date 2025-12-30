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
        cout << "Memory free for node with data " << data <<endl;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail (Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Finding Position
    while (cnt < position-1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last postion
    if (temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }
    
    Node* nodeToInser = new Node(data);

    nodeToInser->next = temp->next;
    temp->next = nodeToInser;
    
    
}

void deleteNode(int position, Node* &head, Node* &Tail){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        // memory free krna hoga 
        temp->next = NULL;
        delete temp;
    }else{
        // deleting at position

        Node* currentNode = head;
        Node* prevNode = NULL;
        
        int cnt = 1;
        while (cnt < position)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
            cnt++;
        }
        prevNode->next = currentNode->next;
        if(currentNode->next == NULL){
            Tail = prevNode;
        }

        currentNode->next = NULL;
        delete currentNode;
        
    }
}

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
}


// For Loop Checking if exit or not
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

// FloydDetectLoop algorithm
Node* FloydDetectLoop(Node* head){
    if (head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast -> next;
        }

        slow = slow->next;

        if(slow == fast){
            return slow;
        }
        
    }
    return NULL;
    
    
}


// get First node with starting loop
Node* getStartingNodeofLoop(Node* head){
    if (head == NULL)
    {
        return NULL;
    }

    Node* intersectingNode = FloydDetectLoop(head);
    Node* slow = head;

    while (slow != intersectingNode)
    {
        slow = slow->next;
        intersectingNode = intersectingNode->next;
    }

    return slow;
    
    
}

// removeLoop by me
void removeLoop(Node* head){
    if(head == NULL)
        return;

    Node* intersect = FloydDetectLoop(head);
    Node* slow = head;
    Node* pre = NULL;

    while (slow != intersect)
    {
        slow = slow->next;
        pre = intersect;
        intersect = intersect->next;

    }
    pre->next = NULL;
    
}
// by sir
// void removeLoop(Node* head){
//     if(head == NULL)
//         return;

//     Node* intersect = getStartingNodeofLoop(head);
//     Node* temp = intersect;
    

//     while (temp->next != intersect)
//     {
//         temp = temp->next;

//     }
//     temp->next = NULL;
    
// }


int main(){

    Node * node1 = new Node(10);
    Node* Tail = node1;
    Node* Head = node1;

    // print(Head);
    insertAtTail(Tail, 12);
    insertAtTail(Tail, 13);
    // print(Head);
    insertAtPosition(Head,Tail,2,32);
    // print(Head);
    insertAtPosition(Head,Tail,5,33);
    // print(Head);

    // deleteNode(2,Head, Tail);
    
    print(Head);
    Tail->next = Head->next;

    if (FloydDetectLoop(Head))
    {
        cout << "Circle is Found" << endl;
    }
    else{
        cout << "Circle is not Avail" << endl;
    }

    Node* ans = getStartingNodeofLoop(Head);

    cout << "Starting Node of Loop : " << ans->data << endl;

    removeLoop(Head);
    cout << "Removed LOOP" << endl;
    print(Head);
    if (FloydDetectLoop(Head) != NULL)
    {
        cout << "Circle is Found" << endl;
    }
    else{
        cout << "Circle is not Avail" << endl;
    }
    

    cout <<"Tail: " << Tail->data << endl;
    cout <<"Head: "<< Head->data << endl;


    return 0;
}