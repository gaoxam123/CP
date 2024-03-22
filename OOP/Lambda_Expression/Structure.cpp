#include<bits/stdc++.h>
using namespace std;

// [] () -> return_type specifiers{};


// as function parameters
void foo(function<void(int)> l) {
    l(10);
}

void foo(void (*l)(int)) {
    l(10);
}

void foo(auto l) {
    l(10);
}
// foo([] (int x) {cout << x;});
// auto l = [] (int x) {cout << x:}; -> foo(l);

// return from functions
function<void(int)> foo2() {
    return [] (int x) {cout << x << endl;};
}

void(*foo1())(int x) {
    return [](int x) {cout << x << endl;};
}

auto foo3() {
    return [](int x) {cout << x << endl;};
}
// auto l = foo3(); -> l(10);

// predicates
void print_if(vector<int> nums, bool(*predicate)(int)) {
    for(int i: nums) {
        if(predicate(i)) 
            cout << i;
    }
}

int main() {
    [] () {cout << "Hi";}();
    int x{10};
    [] (int x) {cout << x;}(100); // stateless -> captures nothing from the environment -> x inside is different from the initiated one

    const int n{3};
    int nums[n]{10, 20, 30};

    auto sum = [] (int nums[], int n) {
        int sum{0};
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
        }
        return sum;
    };
    cout << sum(nums, 3); // displays 60

    int t1{88}, t2{75};

    auto bonus = [] (int &s1, int &s2, int bonus_points) {
        s1 += bonus_points;
        s2 += bonus_points;
    };    

    bonus(t1, t2, 5);

    cout << t1 << " " << t2 << endl;// 93 and 80

    t1 = 88, t2 = 75;

    auto bonu = [] (int *s1, int *s2, int bonus_points) {
        *s1 += bonus_points;
        *s2 += bonus_points;
    };
    bonu(&t1, &t2, 5);
    cout << t1 << " " << t2 << endl;

    vector<int> scores {93, 88, 75, 68, 65};
    auto bnu = [] (auto &scores, int bonus) {
        for(auto &score: scores) 
            score += bonus;
    };
    bnu(scores, 5);

    int num1{10};
    float num2{20.5};

    auto l = [] (auto x) {cout << x << endl;};
    l(num1);
    l(num2);

    vector<int> v{1, 2, 3};
    print_if(v, [](auto x) {return x % 2 == 0;});
    print_if(v, [](auto x) {return x % 2 == 1;});
}