#include <bits/stdc++.h>
using namespace std;

class Player {
public:
    string name{"player"};
    int health{0};
    int xp{0};

    void talk(string text_to_say) {
        cout << name << "says" << text_to_say << endl;
    }
    bool is_dead();
};

class Account {
public:
    string name{"account"};
    double balance{0};

    bool deposit(double bal) {
        balance += bal;
        cout << "In deposit" << endl;
    }
    bool withdraw(double bal) {
        balance -= bal;
        cout << "In withdraw" << endl;
    }
};

int main() {
    Account frank_account;
    Account jim_account;

    Player frank;
    Player hero;

    Player players[] {frank, hero};
    vector <Player> player_vec{frank};
    player_vec.push_back(hero);

    Player *enemy{nullptr};
    enemy = new Player;
    delete enemy;

    // access class members
    frank_account.deposit(1000.0);
    Account *new_account = new Account();
    new_account->deposit(1000.0);
    (*new_account).deposit(1000.0);

    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;

    (*enemy).name = "Enemy";
    enemy->xp = 12;
}