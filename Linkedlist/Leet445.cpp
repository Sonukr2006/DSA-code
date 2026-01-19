#include<iostream>
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
void insertAtTail (Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
};
Node* reverse(Node* &l1){
        if(l1 == NULL || l1->next == NULL){
            return l1;
        }

        Node* curr = l1;
        Node* pre = NULL;
        Node* right = NULL;

        while(curr != NULL){
            right = curr->next;
            curr->next = pre;
            pre = curr;
            curr = right;
        }

        return pre;
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
Node* addTwoNumbers(Node* first, Node* second) {
        first = reverse(first);
        second = reverse(second);

        Node* temp1 = first;
        Node* temp2 = second;
        Node* ans = new Node(-1);
        Node* dummy = ans;
        int carry = 0;
        int sum = 0;

        while(temp1 != NULL && temp2 != NULL){
            sum = carry + temp1->data + temp2->data;
            int digit = sum%10;
            // Node* node = new Node(digit);
            insertAtTail(ans, digit);
            print(dummy); 
            cout << "Add in head" << endl;
            carry = sum/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
            // delete node;
        }
        while(temp1 != NULL){
            sum = carry + temp1->data;
            int digit = sum %10;
            insertAtTail(ans, digit);
            temp1=temp1->next;
            
        }
        while(temp2 != NULL){
            sum = carry + temp2->data;
            int digit = sum %10;
            insertAtTail(ans, digit);
            temp2 = temp2->next;
            
        }
        ans = reverse(dummy->next);
        return ans;
        
    }
int main(){
    Node* node = new Node(10);
    Node* head = node;
    insertAtTail(node, 1);
    insertAtTail(node, 2);
    insertAtTail(node, 5);
    insertAtTail(node, 8);
    print(head);
    Node* temp = reverse(head);

    Node* node1 = new Node(11);
    Node* head1 = node1;
    insertAtTail(node1, 1);
    insertAtTail(node1, 2);
    insertAtTail(node1, 5);
    insertAtTail(node1, 8);
    print(head1);
    Node* temp1 = reverse(head1);
    
    Node* d = addTwoNumbers(head, head1);
    cout<<"add" << endl;
    print(d);

}