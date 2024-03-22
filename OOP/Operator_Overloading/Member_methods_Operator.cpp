#include <bits/stdc++.h>
using namespace std;

class Mystring {
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring operator-() const;
    bool operator==(const Mystring &rhs) const;
    Mystring operator+(const Mystring &rhs) const;
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

Mystring Mystring::operator-() const {
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for(size_t i = 0; i < strlen(str); i ++) {
        buff[i] = tolower(buff[i]);
    }
    Mystring tmp{buff};
    delete [] buff;
    return tmp;
}

bool Mystring::operator==(const Mystring &rhs) const {
    if(strcmp(rhs.str, str) == 0) return true;
    return false;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    size_t buff_size = strlen(str) + strlen(rhs.str);
    char *buff = new char[buff_size + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring tmp{buff};
    delete [] buff;
    return tmp;
}