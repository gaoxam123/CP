#include <iostream>
using namespace std;

class Printable{
    friend ostream &operator<<(ostream &os, const Printable &obj);
public:
    virtual void print(ostream &os) const = 0;
    virtual ~Printable() {}
};

ostream &operator<<(ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}

class Account: public Printable  {
    //friend std::ostream &operator<<(std::ostream &os, const Account &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(ostream &os) const override {os << "Account display" << endl;}
    virtual ~Account() {}
};

// std::ostream &operator<<(std::ostream &os, const Account &acc) {
//     os << "Account display";
//     return os;
// }

class Checking: public Account  {
    //friend std::ostream &operator<<(std::ostream &os, const Checking &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(ostream &os) const override {os << "Checking Account display" << endl;}
    virtual ~Checking() {  }
};

// std::ostream &operator<<(std::ostream &os, const Checking &acc) {
//     os << "Checking display";
//     return os;
// }

class Savings: public Account {
    //friend std::ostream &operator<<(std::ostream &os, const Savings &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(ostream &os) const override {os << "Savings Account display" << endl;}
    virtual ~Savings() {  }
};

// std::ostream &operator<<(std::ostream &os, const Savings &acc) {
//     os << "Savings display";
//     return os;
// }
class Trust: public Account  {
    //friend std::ostream &operator<<(std::ostream &os, const Trust &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(ostream &os) const override {os << "Trust Account display" << endl;}
    virtual ~Trust() {}
};

// std::ostream &operator<<(std::ostream &os, const Trust &acc) {
//     os << "Trust display";
//     return os;
// }

int main() {
    Account *p1 = new Account();
    std::cout << *p1<< std::endl;

    Account *p2 = new Checking();
    std::cout << *p2<< std::endl;
   
//    Account a;
//    std::cout << a<< std::endl;
//    
//    Checking c;
//    std::cout << c << std::endl;
//
//    Savings s;
//    std::cout << s << std::endl;
//    
//    Trust t;
//    std::cout << t << std::endl;

    delete p1;  
    delete p2;
    return 0;
}

