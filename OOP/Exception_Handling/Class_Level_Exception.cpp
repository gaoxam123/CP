#include<bits/stdc++.h>
using namespace std;

class IllegalBalanceException{
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
};

class Account {
private:
    double balance;
    string name;
public:
    string get_name(){return name;}
    Account(string name = "None", double balance = 0.0);
    ~Account() {}
};

Account::Account(string name, double balance) : name{name}, balance{balance} {
    if(balance < 0.0) 
        throw IllegalBalanceException();
}

int main() {
    try {
        unique_ptr<Account> acc = make_unique<Account>("moe", -10.0);
        cout << acc->get_name() << endl;
    }
    catch (const IllegalBalanceException &er) {
        cerr << "no neg balance" << endl;
    }
}