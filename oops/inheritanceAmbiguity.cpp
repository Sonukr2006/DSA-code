#include<iostream>
using namespace std;


class Animal{
    public:
    int weight;
    int legs;

    void speak(){
        cout<< "barking..." << endl << endl;
    }
};
class Human{
    public:
    int height;

    void speak(){
        cout<< "speaking..." << endl << endl;
    }
};

class blackDog : public Human, public Animal{

};




int main(){


    blackDog d;
    // Inheritance Ambiguity
    d.Human::speak();
    d.Animal::speak();

    return 0;
}