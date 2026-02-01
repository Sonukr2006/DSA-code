#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q){
    if (q.empty())
        return;
    
    int ele = q.front();
    q.pop();
    print(q);
    cout <<" " << ele << " ";
    q.push(ele);
}

int main(){
    queue<int> q;

    q.push(10);
    q.push(25);
    q.push(53);

    cout << "Front Ele of Queue: "<< q.front() << endl;
    cout << "Size of Queue: " << q.size() << endl;
    q.push(25);
    q.push(53);
    q.push(53);
    q.pop();
    cout << "Size of Queue: " << q.size() << endl;
    cout << "Back of Queue: " << q.back() << endl;
    cout << "Front Ele of Queue: "<< q.front() << endl;


    print(q);








    if(q.empty())
        cout << "Empty ......Njnd" << endl;
    else
        cout << "Not Empty" << endl;


    cout << endl;
    return 0;
}