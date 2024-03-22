#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

void do_withdraw(Account &acc, double amount) {
    acc.withdraw(amount);
}

int main() {
    Account a;
    Account &ref = a;
    ref.withdraw(1000); // Account::withdraw
    do_withdraw(a, 1000); // Account::withdraw

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000); //Trust::withdraw
    do_withdraw(t, 1000); //Trust::withdraw
}