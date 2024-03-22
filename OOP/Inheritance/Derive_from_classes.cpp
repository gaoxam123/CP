#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    double bal;
    string name;
    void deposit(double amount);
    void withdraw(double amount);
    Account();
    ~Account();
};

Account::Account() : bal{0}, name{"An Account"} {}
Account::~Account() {}

void Account::deposit(double amount) {}
void Account::withdraw(double amount) {}

class Savings_Account: public Account {
public:
    double int_rate;
    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);
    void withdraw(double amount);
};

Savings_Account::Savings_Account() : int_rate{3.0} {}
Savings_Account::~Savings_Account() {}