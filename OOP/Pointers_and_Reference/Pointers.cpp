#include <bits/stdc++.h>
using namespace std;

void display(const vector <string> *const v) {
    for(auto str: *v) {
        cout << str << endl;
    }
}

void execute(int *array, int sentinel) {
    while(*array != sentinel) {
        cout << *array++ << endl;
    }
}

int *largest_int(int *int_ptr1, int *int_ptr2) {
    if(*int_ptr1 > *int_ptr2) 
        return int_ptr1;
    else
        return int_ptr2;
}

int *create_array(size_t size, int init_value = 0) {
    int *new_storage {nullptr};
    new_storage = new int[size];
    for(size_t i{0}; i < size; i ++) {
        *(new_storage + i) = init_value;
    }
    return new_storage;
}

int main() {
    int *int_prt{nullptr};
    int num{10};
    // value of num: 10
    // size of num: 4
    // address of num: &num
    int *p;
    // value of p: address of another variable
    // address of p: &p
    // sizeof p: 4
    p = nullptr;
    // value of p: 0
    int score{10};
    double high_tmp{100.7};
    int *score_ptr{nullptr};
    score_ptr = &score;
    //score_ptr = &high_tmp; //error
    int score{100};
    score_ptr = &score;

    //dereference of a pointer
    *score_ptr = 2000; 
    vector <string> names{"a", "b", "c"};
    vector <string> *vector_ptr{nullptr};
    vector_ptr = &names;
    (*vector_ptr).at(0) = "a";
    for(auto name: *vector_ptr) {
        cout << name << " "; // a b c
    }

    //dynamic memory allocation
    int *ptr{nullptr};
    ptr = new int; //allocate an int on the heap
    cout << ptr << endl; // address of the new int on the heap
    cout << *ptr << endl; // value of the new int
    *ptr = 100;
    cout << *ptr << endl; // new int gets new value of 100
    delete ptr; // free the allocated storage on the heap
    int *array_ptr{nullptr};
    int size{};
    array_ptr = new int[size]; //allocate new array on the heap
    delete [] array_ptr;

    //arrays and pointers
    int scores[]{100, 95, 98};
    cout << scores << endl; //address of the first element in the array
    cout << *scores << endl; //100
    int *ptr{scores};
    cout << ptr << endl; // address of 100 = 0x61ff10
    cout << *ptr << endl; // 100
    cout << ptr[0] << endl; //100
    cout << ptr[1] << endl; //95
    cout << ptr[2] << endl; //98
    // cout << (ptr + 1) << endl; address of the next element (adding the size of 1 int to the pointer value) => 4 bytes away
    cout << (ptr + 1) << endl; //95
    cout << (ptr + 2) << endl; //98
    // array_name[index] = pointer_name[index]
    // *(array_name + index) = *(pointer_name + index)
    int a[]{100, 95, 89, 68, -1};
    int *a_ptr {a};

    while(*a_ptr != -1) {
        cout << *a_ptr << endl;
        a_ptr ++;
    }
    a_ptr = a;
    while(*a_ptr != -1) {
        cout << *a_ptr ++ << endl; // first print out the value of *a_ptr then increment the pointer, not the referenced value, same thing as above
    }

    // constant and pointers: the data pointed by the pointer remains but the address can be change
    int h_score{100};
    int l_score{65};
    const int *s_ptr{&h_score}; // constant int
    // *s_ptr = 86; error
    // s_ptr = &l_score; ok
    //constant pointer is differen
    int *const s_ptr{&h_score};
    //*s_ptr = 86; ok
    //s_ptr = &l_score; error
    const int *const s_ptr{&h_score}; // both can't be changed

    // pointers to functions

    //return pointers from functions
    int c{100};
    int b{200};
    int *largest_ptr{nullptr};
    largest_ptr = largest_int(&c, &b);
    cout << *largest_int << endl; // 200

    int *my_array;
    my_array = create_array(100, 20);
    delete [] my_array;
    return 0;
}

void double_data(int *int_ptr) {
    *int_ptr *= 2;
}