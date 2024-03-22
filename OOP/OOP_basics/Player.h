#ifndef _PLAYER_H_
#define _PLAYER_H_  
#include <string>
using namespace std;

class Player {
private:
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

#endif