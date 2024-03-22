#include <bits/stdc++.h>
using namespace std;

class Player{
private:
    string name;
    int hp;
    int xp;

public:
    string get_name() const {return name;}
    void set_name(string val) {name = val;} 
    Player(string name = "None", int hp = 0, int xp = 0);
    ~Player();
};

Player::Player(string name, int hp, int xp) : name{name}, hp{hp}, xp{xp} {}

void display(const Player &p) {
    cout << p.get_name() << endl;
}

int main() {
    const Player Villain{"Villain", 100, 100};
    Player hero{"Hero", 100, 100};
    display(Villain);
}