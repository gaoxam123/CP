#include<bits/stdc++.h>
using namespace std;
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

// can be copied and assigned

class Test {
private:
    int data;
public:
    Test() : data{0} {}
    Test(int data) : data{data} {}
    int get_data() const {return data;}
    ~Test() {}
};

void func(shared_ptr<Test> p) { // call a pointer pointing to a Test object 
    cout << p.use_count() << endl;
}

int main() {
    shared_ptr<int>  p1{new int {100}};
    cout << p1.use_count() << endl;

    shared_ptr<int> p2{p1};
    cout << p1.use_count() << endl;

    p1.reset();
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;

    shared_ptr<Test> ptr = make_shared<Test>(100);
    func(ptr);
    cout << ptr.use_count() << endl;

    {
        shared_ptr<Test> ptr1 = ptr;
        cout << ptr.use_count() << endl;
        {
            shared_ptr<Test> ptr2 = ptr;
            cout << ptr.use_count() << endl;
            ptr.reset();
        }
        cout << ptr.use_count() << endl;
    }
    cout << ptr.use_count() << endl;

    shared_ptr<Account> acc1 = make_shared<Trust_Account>("larry", 1000, 3.1);
    shared_ptr<Account> acc2 = make_shared<Checking_Account>("larry", 1000, 3.1);
    shared_ptr<Account> acc3 = make_shared<Savings_Account>("larry", 1000, 3.1);

    vector<shared_ptr<Account>> acc;
    acc.push_back(acc1);
    acc.push_back(acc2);
    acc.push_back(acc3);

    for(const auto &acc: acc) {
        cout << *acc << endl;
        cout << acc.use_count() << endl;
    }
}