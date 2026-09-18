#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* creationTree(node* root){
    cout << "Enter data : " ;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;
    
    cout << "Enter data for inserting at left node :" << data << " " ;
    root->left = creationTree(root->left);

    cout << "Enter data for inserting at right node :" << data << " " ;
    root->right = creationTree(root->right);

    return root; 
}

void inOrder(node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data  << " ";
    inOrder(root->right);
}
void preOrder(node* root){
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    
}
void postOrder(node* root){
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    

    while (!q.empty())
    {
        node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

}

// in this using seprate like technique which is help to printing level wise 
// add null node in queue for separate levels
// if Sonu you are not understand, then dry run right now.
void levelWiseTree(node* root){
    queue<node* > q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}


int main(){

    node* root = NULL;
    root = creationTree(root);
    // cout << "hello" << endl;

    cout << endl;
    levelWiseTree(root);


    return 0;
}