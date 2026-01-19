#include<iostream>
#include<stack>
using namespace std;
void deletemid(stack<int>&s, int count, int size){
    if(count == size/2){
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    deletemid(s, count+1, size);
    s.push(num);
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(8);

    int size = s.size();
    int count = 0;
    deletemid(s, count, size );

    s.pop();
    cout << s.top() << endl;
    return 0;
}