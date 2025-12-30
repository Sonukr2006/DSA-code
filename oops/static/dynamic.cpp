#include<iostream>
using namespace std;

class Hero{
    int level;
    
    public:
    char health;

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

};
int main(){

    // static allocation
    Hero sonu;
    sonu.health = 'a';
    sonu.setLevel(70);
    cout << sonu.health << endl;
    cout << sonu.getLevel() << endl;

    // Dynamic allocation

    Hero* Sonu = new Hero;
    // Hero* = static memory me ek Sonu block create hua hoga jisme address store hua hoga ek Hero object ka 
    (*Sonu).setLevel(30);
    (*Sonu).setHealth('A');
    cout << (*Sonu).health << endl;
    cout << (*Sonu).getLevel() << endl;

    // Always uses 

    Sonu->setLevel(40);
    Sonu->setHealth('B');
    cout << Sonu->health << endl;
    cout << Sonu->getLevel() << endl;

    delete Sonu;

    return 0;
}