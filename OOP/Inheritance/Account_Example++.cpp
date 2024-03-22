#include <bits/stdc++.h>
using namespace std;

class Account {
    friend ostream &operator<<(ostream &os, const Account &rhs);
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    string name;
    double balance;
public:
    Account(string name = def_name, double balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

Account::Account(string name, double balance) : name{name}, balance{balance} {}
bool Account::deposit(double amount) {
    if(amount < 0) return false;
    balance += amount;
    return true;
}
bool Account::withdraw(double amount) {
    if(amount > balance) return false;
    balance -= amount;
    return true;
}
double Account::get_balance() const {return balance;}
ostream &operator<<(ostream &os, const Account &rhs) {
    os << rhs.name << " " << rhs.balance;
    return os;
}

class Savings_Account: public Account {
    friend ostream &operator<<(ostream &os, const Savings_Account &rhs);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    // withdraw from Account
};

Savings_Account::Savings_Account(string name, double balance, double int_rate) : Account{name, balance}, int_rate{int_rate} {}
bool Savings_Account::deposit(double amount) {
    amount += amount * int_rate / 100;
    Account::deposit(amount);
}
ostream &operator<<(ostream &os, const Savings_Account &rhs) {
    os << rhs.name << " " << rhs.balance << " " << rhs.int_rate << endl;
    return os;
}



// duplication because of static
void display(const vector<Account> &accounts){
    for(const auto &acc: accounts) cout << acc << endl; 
}
void deposit(vector<Account> &accounts, double amount){
    for(auto &acc: accounts) {
        if(acc.deposit(amount)) cout << amount << " to " << acc << endl;
        else cout << amount << " not to " << acc << endl;
    } 
}
void withdraw(vector<Account> &accounts, double amount) {
    for(auto &acc: accounts) {
        if(acc.withdraw(amount)) cout << amount << " from " << acc << endl;
        else cout << amount << " not from " << acc << endl;
    } 
}

void display(const vector<Savings_Account> &accounts) {
    for(const auto &acc: accounts) cout << acc << endl; 
}
void deposit(vector<Savings_Account> &accounts, double amount){
    for(auto &acc: accounts) {
        if(acc.deposit(amount)) cout << amount << " to " << acc << endl;
        else cout << amount << " not to " << acc << endl;
    } 
}
void withdraw(vector<Savings_Account> &accounts, double amount){
    for(auto &acc: accounts) {
        if(acc.withdraw(amount)) cout << amount << " from " << acc << endl;
        else cout << amount << " not from " << acc << endl;
    } 
}

int main() {

}