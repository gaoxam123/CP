#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"
#include <bits/stdc++.h>
using namespace std;

class Checking_Account: public Account {
    friend ostream &operator<<(ostream &os, const Checking_Account &rhs);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
protected:
    int fee{1.5};
public:
    Checking_Account(string name = def_name, double balance = def_balance);
    bool withdraw(double amount);
};

#endif