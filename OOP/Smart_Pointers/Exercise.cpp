#include <bits/stdc++.h>
using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{0} {cout << "Test constructor" << endl;}
    Test(int data) : data{data} {cout << "Test constructor" << endl;}
    int get_data() const {return data;}
    ~Test() {cout << "Test destructor" << endl;}
};

unique_ptr<vector<shared_ptr<Test>>> make() {
    unique_ptr<vector<shared_ptr<Test>>> ptr = make_unique<vector<shared_ptr<Test>>>();
    return ptr;
}
void fill(vector<shared_ptr<Test>> &vec, int num) {
    int x;
    for(int i = 0; i < num; i ++) {
        cin >> x;
        shared_ptr<Test> tmp = make_shared<Test>(x);
        vec.push_back(tmp);
    }
}
void display(const vector<shared_ptr<Test>> &vec) {
    for(const auto &ptr: vec) {
        cout << (*ptr).get_data() << endl;
    }
}

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
}