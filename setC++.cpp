#include<iostream>
#include<set>
#include<unordered_set>

using namespace std;

int main(){

    set<int> s = {1, 2, 2, 5, 5, 6, 8};
    unordered_set<int> s2 = {1, 2, 2, 5, 5, 6, 8};

    for(auto i : s){
        cout << i << endl;
    }

    cout << "ab se unordered set ka value" << endl;

    for(int i : s2){
        cout << i << endl;
    }
    return 0;
}