#include <bits/stdc++.h>
using namespace std;
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
// can't be copied or assigned
// can be moved
// is unique
class Test {
private:
    int data;
public:
    Test() : data{0} {}
    Test(int data) : data{data} {}
    int get_data() const {return data;}
    ~Test() {}
};

int main() {
    unique_ptr<Test> t1 {new Test{100}};
    t1.get(); // return the address
    t1.reset();
    unique_ptr<Test> t2 = make_unique<Test>(1000);
    unique_ptr<Test> t3;
    // t3 = t1; error
    t3 = move(t1); // can be moved

    unique_ptr<Account> a1 = make_unique<Checking_Account>("Moe", 5000); // Account is abstract -> can't be constructed
    cout << *a1 << endl;
    a1->deposit(5000);

    vector<unique_ptr<Account>> acc;

    acc.push_back(make_unique<Checking_Account>("james", 1000));
    acc.push_back(make_unique<Savings_Account>("james", 1000));
    acc.push_back(make_unique<Trust_Account>("james", 1000));

    for(const auto &acc: acc) {
        cout << *acc;
    }
}