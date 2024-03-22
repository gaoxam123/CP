#include <bits/stdc++.h>
#include "Trust_Account.h"
using namespace std;

Trust_Account::Trust_Account(string name, double balance, double int_rate) : Savings_Account{name, balance, int_rate} {}
bool Trust_Account::deposit(double amount) {
    if(amount >= 0) {
        if(amount >= 5000) amount += bonus;
        Savings_Account::deposit(amount);
        return true;
    }
    return false;
}
bool Trust_Account::withdraw(double amount) {
    if(amount < balance * 0.2 && check < 4) {
        Savings_Account::withdraw(amount);
        check ++;
        return true;
    }
    return false;
}
ostream &operator<<(ostream &os, const Trust_Account &rhs) {
    os << "[Trust_Account: " << rhs.name << ": " << rhs.balance << ", " << rhs.int_rate << "%]";
    return os;
}