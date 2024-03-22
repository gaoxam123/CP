#include <bits/stdc++.h>
#include "Player.h"
using namespace std;

int Player::num_players{0};

Player::Player(string name, int hp, int xp) : name{name}, hp{hp}, xp{xp} {++num_players;}
Player::Player(const Player &source) : Player{source.name, source.hp, source.xp} {}
Player::~Player() {--num_players;}

int Player::get_num_players() {
    return num_players;
}