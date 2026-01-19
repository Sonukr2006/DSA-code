#include<iostream>
#include<stack>

int main(){
    std::string str = "56853";

    std::stack<char> s;
    for(char ch: str){
        s.push(ch);
    }
    std::cout<<s.size() << std::endl;
    std::string ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    std::cout << ans << std::endl;
}