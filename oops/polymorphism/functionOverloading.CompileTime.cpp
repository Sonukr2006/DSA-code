#include<iostream>
using namespace std;


class Animal{
    public:
    int weight;
    int legs;

    // function Overloading Polymorphism 
    void speak(){
        cout<< "barking..." << endl << endl;
    }
    // agr same function or type v same hai to hme different argument dena hoga
    void speak(string name){
        cout << "Barking.." << endl;
    }
    // cannot overload functions distinguished by return type alone
    // int speak(){
    // }

    int speak(char name){
        cout << "hezzzezezezezeee" << endl;
        return 1;
    }
};



int main(){



    return 0;
}