#include <bits/stdc++.h>
using namespace std;

class Player{
private:
    string name;
    int hp;
    int xp;

public:
    string get_name() {return name;}
    int get_hp() {return hp;}
    int get_xp() {return xp;}
    Player(string name = "None", int hp = 0, int xp = 0);
    //Copy Constructor
    Player(const Player &source);
    //Destructor
    ~Player() {cout << "Destructor for " << name << endl;}
};

Player::Player(string name, int hp, int xp) : name{name}, hp{hp}, xp{xp} {cout << "Constructor for " << name << endl;}

Player::Player(const Player &source) : Player{source.name, source.hp, source.xp} //: name{source.name}, hp{source.hp}, xp{source.xp} 
{cout << "Copy Constructor of " << source.name <<endl;}

void display(Player p) {
    cout << p.get_name() << endl;
    cout << p.get_hp() << endl;
    cout << p.get_xp() << endl;
}

int main() {
    Player empty;
    display(empty);
}