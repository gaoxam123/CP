#include <bits/stdc++.h>
using namespace std;

class Player {
private:
    string name;
    int hp;
    int xp;
public:
    void talk(string txt) {cout << name << "says" << txt << endl;}
    bool is_dead();
};

int main() {
    Player frank;
    frank.talk("hello there");
}