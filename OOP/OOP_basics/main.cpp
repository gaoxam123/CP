#include <bits/stdc++.h>
#include "Player.h"
using namespace std;

void display() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
    display();
    Player *enemy = new Player("Enemy", 100, 100);
    display();
    delete enemy;
    display();
}