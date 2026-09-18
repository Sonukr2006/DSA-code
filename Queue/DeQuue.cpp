#include<iostream>
#include<queue>
using namespace std;

int main(){
    deque<int> q;

    q.push_front(34);
    q.push_front(45);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop_back();
    cout << q.front() << endl;
}