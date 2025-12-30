#include<iostream>
using namespace std;

class Human{
    public:
    void speak(){
        cout << "speaking...." << endl;
    }
};

class boys : public Human {

    public:
    void speak(){ 
        // overriding concept
        cout << "Kya haal hai" << endl;
    }
};




int main(){

    Human he;
    he.speak();

    boys b;
    b.speak();

    
    b.Human::speak();

    return 0;
}