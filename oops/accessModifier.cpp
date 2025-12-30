#include<iostream>
using namespace std;

class Hero{
    private:
    int health= 6;
    public:
    char level;


//  getter hai agr class me sare variable private hai to getter ko public
//  banana hi hoga tab ja ke main() me use kr skte hai
    int getHealth(){
        return health;
    }
//  setter hai agr class me sare variable private hai to setter ko public
//  banana hi hoga tab ja ke main() me use kr skte hai
  
    void setHealth(int h){
        health = h;
    }

};
int main(){
    Hero h1;
    h1.setHealth(10);
    cout << h1.getHealth() << endl;
    return 0;
}