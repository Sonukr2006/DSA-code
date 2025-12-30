#include<iostream>
using namespace std;

class Human{
    public:
    int a;
    int b;

    // This is an inline member function overload of the + operator for the Human class, 
    // which outputs the difference between the member variable a of the current object and that of another Human object to the standard output. It does not return a value or perform arithmetic addition as typically expected from operator+.
    void operator+(Human &obj){
        cout << "output:" << this->a - obj.a << endl;
    }

    int operator()(){
        return 1;
    }

};


int main(){

    Human obj1;
    obj1.a = 5;
    Human obj2;
    obj2.a = 8;
    obj1 + obj2;

    cout << obj1() << endl;

    return 0;
}