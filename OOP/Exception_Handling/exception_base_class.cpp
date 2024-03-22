#include<bits/stdc++.h>
using namespace std;

class IllegalBalanceException: public exception{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char *what() const noexcept {
        return "Illegal balance exception";
    }
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
        cerr << er.what() << endl; // Illegal balance exception
    }
}