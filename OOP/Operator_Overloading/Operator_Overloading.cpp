#include <bits/stdc++.h>
using namespace std;

class Mystring {
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
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

int main() {
    Mystring empty;
    Mystring larry{"larry"};
    Mystring name{larry};

    empty.display();
    larry.display();
    name.display();
}