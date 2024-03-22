#include <bits/stdc++.h>
using namespace std;

class Player{
private:
    static int num_players;
    string name;
    int hp;
    int xp;

public:
    static int get_num_players();
    string get_name() const {return name;}
    void set_name(string val) {name = val;} 
    Player(string name = "None", int hp = 0, int xp = 0);
    ~Player();
};