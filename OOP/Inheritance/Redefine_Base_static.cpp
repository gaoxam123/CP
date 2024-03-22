#include <bits/stdc++.h>
using namespace std;

class Account{
    friend ostream &operator<<(ostream &os, const Account &rhs);
protected:
    double balance;
public:
    Account();
    Account(double balance);
    void deposit(double amount);
    void withdraw(double amount);
};

Account::Account() : Account(0.0) {}
Account::Account(double balance) : balance{balance} {}

void Account::deposit(double amount) {balance += amount;}
void Account::withdraw(double amount) {
    if(amount <= balance) balance -= amount;
    else return;
}

ostream &operator<<(ostream &os, const Account &rhs) {
    os << rhs.balance;
    return os;
}

class Savings_Account: public Account {
    friend ostream &operator<<(ostream &os, const Savings_Account &rhs);
protected:
    double int_rate;
public:
    Savings_Account();
    Savings_Account(double balance, double int_rate);
    void deposit(double amount);
    //withdraw is inherited
};

Savings_Account::Savings_Account(double balance, double int_rate) : Account{balance}, int_rate{int_rate} {}
Savings_Account::Savings_Account() : Savings_Account{0.0, 0.0} {}

void Savings_Account::deposit(double amount) {
    amount += amount * int_rate / 100;
    Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Savings_Account &rhs) {
    os << rhs.balance << " " << rhs.int_rate << endl;
    return os;
}

int main() {
    Account a{1000};
    Savings_Account b{1000, 50};
    Account *ptr = new Savings_Account();
    ptr->deposit(10); // this calls the deposit in the Account class, since this is just static binding
}