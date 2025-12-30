#include<iostream>
using namespace std;


class Animal{
    public:
    int weight;
    int legs;

    void bark(){
        cout<< "barking..." << endl << endl;
    }
};

class Human{
    public:
    int age;
    int height;

    void speak(){
        cout << "speaking......." << endl;
    }

};

// multiple Inheritance

class Blackman : public Human, public Animal{

};



int main(){


    Blackman b;
    b.speak();
    b.bark();

    return 0;
}