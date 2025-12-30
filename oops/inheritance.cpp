#include<iostream>
using namespace std;

class Human{
    public:
    string name;
    int height;
    int age;

public:
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }

    void setHeight(int height){
        this->height = height;
    }
    int getHeight(){
        return this->height;
    }

    void setAge(int age){
        this->age = age;
    }
    int getAge(){
        return this->age;
    }
     
};


class Male : public Human{

    string color;

public:
    void setColor(string name){
        this->color = name;
    }
    string getColor(){
        return this->color;
    }

    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }

    void setHeight(int height){
        this->height = height;
    }
    int getHeight(){
        return this->height;
    }

    void setAge(int age){
        this->age = age;
    }
    int getAge(){
        return this->age;
    }
};



int main (){

    Male Sonu;
  
    Sonu.setHeight(10);
    cout <<   Sonu.height << endl;

    Human sonu;
    // cout << sonu.height << endl;

    return 0;
}