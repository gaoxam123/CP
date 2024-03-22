#include <bits/stdc++.h>
using namespace std;

class Other_Class {
private: 
    int a;
public:
    void display(Player &p);
};

class Player{
private:
    friend void display_player(Player &p);
    friend void Other_Class::display(Player &p);
    friend class Other_Class;
    static int num_players;
    string name;
    int hp;
    int xp;

public:
    static int get_num_players();
    string get_name() {return name;}
    int get_hp(){return hp;}
    int get_xp() {return xp;}
    Player(string name, int hp, int xp);
    Player(const Player &source);
    ~Player();
};

void display_player(Player &p) {
    cout << "fuck";
}