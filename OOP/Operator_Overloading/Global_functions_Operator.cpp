#include <bits/stdc++.h>
using namespace std;

class Mystring {
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring &operator=(Mystring &&rhs);
    Mystring &operator=(const Mystring &rhs);
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

Mystring &Mystring::operator=(const Mystring &rhs) {
    if(this == &rhs) {
        return *this;
    }
    delete [] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);

    return *this;
}

// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (strcmp(lhs.str, rhs.str) == 0);
}

// lowercase
Mystring operator-(const Mystring &obj) {
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for(size_t i = 0; i < strlen(obj.str); i ++) 
        buff[i] = tolower(buff[i]);

    Mystring tmp{buff};
    delete [] buff;
    return tmp;
}

// Concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    Mystring tmp{buff};
    delete [] buff;
    return tmp;
}