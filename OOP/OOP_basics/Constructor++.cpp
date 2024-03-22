#include <bits/stdc++.h>
using namespace std;

class Player{
private:
    string name;
    int hp;
    int xp;

public:
    Player();
    Player(string name);
    Player(string name, int hp, int xp);
    ~Player();
};

//Constructor init list
Player::Player() : name{"None"}, hp{0}, xp{0} {}
Player::Player(string name) : name{name}, hp{0}, xp{0} {}
Player::Player(string name, int hp, int xp) : name{name}, hp{hp}, xp{xp} {}

//Delegating Constructors -> avoid duplicating code

Player::Player(string name, int hp, int xp) : name{name}, hp{hp}, xp{xp} {}
Player::Player() : Player{"None", 0, 0} {}
Player::Player(string name) : Player{name, 0, 0} {}

//Default values for constructors -> reduce number of constructors -> efficiency

class Players{
private:
    string name;
    int hp;
    int xp;

public:
    Players(string name = "None", int hp = 0, int xp = 0);
    ~Players();
};

Players::Players(string name, int hp, int xp) : name{name}, hp{hp}, xp{xp} {}

int main() {
    Players empty; // init values are passed in the constructor
    Players frank{"frank"}; // only the name is newly created
    Players villain{"villain", 100, 100}; // everything overloaded
    Players hero{"hero", 100}; // only the first 2 are overloaded
}