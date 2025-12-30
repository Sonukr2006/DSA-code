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
class animal : public Animal{

};


class Human{
    public:
    int age;
    int height;

    void speak(){
        cout << "speaking......." << endl;
    }

};

// hybrid inheritance
class hybrid : public Animal, public Human{

};





int main(){


    return 0;
}