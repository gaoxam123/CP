#include <bits/stdc++.h>
using namespace std;

class Mystring {
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring &operator=(Mystring &&rhs);
    ~Mystring();
    void display() const;
    int get_length() const;
    const char *get_str() const;
};

Mystring::Mystring() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s) : str{nullptr} {
    if(s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source) : str{nullptr} {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);    
}

Mystring::~Mystring() {
    delete [] str;
}

int Mystring::get_length() const {return strlen(str);}

void Mystring::display() const {
    cout << str << get_length() << endl;
}

const char *Mystring::get_str() const {return str;}

Mystring &Mystring::operator=(Mystring &&rhs) {
    if(this == &rhs) {
        return *this;
    }
    delete [] this->str;
    str = rhs.str;
    rhs = nullptr;
    return *this;
}

int main() {
    Mystring s1;

}