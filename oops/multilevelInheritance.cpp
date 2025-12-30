#include<iostream>
using namespace std;


class Animal{
    public:
    int weight;
    int legs;

    void speak(){
        cout<< "speaking..." << endl << endl;
    }
};
class Dog : public Animal{

};

class blackDog : public Dog{

};




int main(){


    Dog heee;
    heee.speak();

    blackDog d;
    d.speak();

    return 0;
}