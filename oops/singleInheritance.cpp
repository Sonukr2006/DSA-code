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




int main(){


    Dog heee;
    heee.speak();

    return 0;
}