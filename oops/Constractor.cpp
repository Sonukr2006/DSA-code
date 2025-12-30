#include<iostream>
#include<cstring>
using namespace std;

// this : keyword ek pointer ki tarh hai jo current object ka address stored rkhta hai
class Hero{
    int level;
    
    public:
    char *name;
    char health;
    static int timeToComplete;

    static int random(){
        // Static func sirf static member ko call kr skte hai
        
        return timeToComplete;
    }

    void setHealth(char healt){
        health = healt;
    }
    int getHealth(){
        return health;
    }

    void setLevel(int Level){
        level = Level;
    }
    int getLevel(){
        return level;
    }


    void print(){
        cout <<"[ Name: "<< this->name << ", " ;
        cout << "Level: "<< this->level << ", ";
        cout <<"Health: "<< this->health << " ] " << endl;
        cout << endl <<endl;
    }



    // defult constractor
    Hero(){
        name = new char[100];
        cout << "Defult constructor called" << endl;
    }
    // Jab v Khud ka constractor create krte hai default wala work nhii krta hai 

    // paramiteries constractor
    Hero(int level, char health){
        cout << "Parametric constructor called" << endl;
        name = new char[100];
        this->level = level;
        this->health = health;
        
    }

    // Copy constractor
    Hero (Hero& temp){
        // deep copy
        cout << "Copy Constractor called" << endl;
        char* ch = new char[strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this->name = ch;
        

        this->level = temp.level;
        this->health = temp.health;
    }

    void setName(char naam[]){
        // shallow copy
        strcpy(this->name, naam);
    }

    // Deconstractor
    ~Hero(){
        cout << "~Deconstractor Call ho gya bhai";
    }
};

 int Hero::timeToComplete = 5;
int main(){


    cout << Hero::timeToComplete << endl;

    Hero a;
    cout << a.timeToComplete << endl << endl;
    a.timeToComplete = 10;
    cout << a.timeToComplete << endl;

    // By stactically
    // jab v default constractor hoga Hero rename; aise v call kr skte hai
    //  agr parametric constractor hoga to argument pass krna hoga
    // Hero rename;
    // agr default constractor v hai aur paramiteries constractor to aap kaise v 
    // object create kr skte hai either rename, sonu() koi v kr skte hai
    // Hero sonu(90, 'A');
    // char name[6] = "Sonu";
    // sonu.setName(name);
    // sonu.print();

    // Hero r(sonu);
    // r.print();

    // sonu.name[0]='D';
    // // copy constractor called
    // sonu.print();
    // r.print();
    
    // sonu = r;
    // sonu.print();
    // r.print();




    // By Dynamically
    // Hero* Sonu = new Hero(80, 'B');  

    // delete Sonu;
    return 0;
}