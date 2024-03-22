#include <bits/stdc++.h>
#include "Checking_Account.h"
using namespace std;

Checking_Account::Checking_Account(string name, double balance) : Account{name, balance} {}
bool Checking_Account::withdraw(double amount) {
    amount += fee;
    Account::withdraw(amount);
}
ostream &operator<<(ostream &os, const Checking_Account &rhs) {
    os << rhs.name << " " << rhs.balance << endl;
    return os;
}