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

class Account {
private:
    string name;
    double balance;

public:
    Account(); // default no-args constructor created by c++ (only created if there's only the default constructor)
    Account(string name, double balance); // if we define a new constructor with args then a no-args constructor is needed since c++ does not create that anymore
    Account(string name);
    Account(double balance);
    ~Account();
};

int main() {
    {
        Player slayer;
        Player frank{"frank", 100, 4};
        Player hero{"hero"};
        Player villain{"villain"};
    }

    Player *enemy = new Player("Enemy", 100, 100);
    delete enemy;
}