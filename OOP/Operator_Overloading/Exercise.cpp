#include <bits/stdc++.h>
using namespace std;

class Mystring {
    friend ostream &operator<<(ostream &os, const Mystring &rhs);
    friend istream &operator>>(istream &is, Mystring &rhs);
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    Mystring &operator=(const Mystring &source);
    Mystring &operator=(Mystring &&source);
    ~Mystring();

    Mystring operator-();
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    Mystring operator+(const Mystring &rhs) const;
    Mystring operator*(int a) const;
    Mystring operator+=(const Mystring &rhs);
    Mystring operator*=(int a);
    Mystring &operator++();
    Mystring operator++(int);

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

Mystring::Mystring(Mystring &&source) {
    strcpy(str, source.str);
    delete [] source.str;
}


Mystring::~Mystring() {
    delete [] str;
}

int Mystring::get_length() const {return strlen(str);}

void Mystring::display() const {
    cout << str << get_length() << endl;
}

const char *Mystring::get_str() const {return str;}

Mystring &Mystring::operator=(const Mystring &source) {
    if(this == &source) {
        return *this;
    }
    delete [] this->str;
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&source) {
    if(this == &source) {
        return *this;
    }
    delete [] this->str;
    str = source.str;
    source.str = nullptr;
    return *this;
}

Mystring Mystring::operator-() {
    char *buff = new char[strlen(this->str) + 1];
    strcpy(buff, this->str);
    for(size_t i = 0; i < strlen(this->str); i ++) {
        buff[i] = tolower(buff[i]);
    }
    Mystring tmp{buff};
    delete [] buff;
    return tmp;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return strcmp(this->str, rhs.str) == 0;
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return strcmp(this->str, rhs.str) != 0;
}

bool Mystring::operator<(const Mystring &rhs) const {
    return strcmp(this->str, rhs.str) < 1;
}

bool Mystring::operator>(const Mystring &rhs) const {
    return strcmp(this->str, rhs.str) > 1;
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

Mystring Mystring::operator*(int a) const {
    char *buff = new char[strlen(this->str) * a + 1];
    strcpy(buff, this->str);
    a --;
    for(int i = 1; i <= a; i ++) {
        strcat(buff, this->str);
    }
    Mystring tmp{buff};
    delete [] buff;
    return tmp;
}

Mystring Mystring::operator+=(const Mystring &rhs) {
    strcat(this->str, rhs.str);
    return *this;
}

Mystring Mystring::operator*=(int a) {
    char *buff = new char[strlen(this->str) + 1];
    strcpy(buff, this->str);
    a --;
    for(int i = 1; i <= a; i ++) {
        strcat(this->str, buff);
    }
    return *this;
}

Mystring &Mystring::operator++() {
    for(size_t i = 0; i < strlen(this->str); i ++) {
        this->str[i] = toupper(this->str[i]);
    }
    return *this;
}

Mystring Mystring::operator++(int) {
    Mystring tmp{*this};
    operator++();
    return tmp;
}

ostream &operator<<(ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

istream &operator>>(istream &is, Mystring &rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return is;
}

int main() {
    Mystring a{"FUCK"};
    Mystring b{"you"};
    Mystring c{"bitch"};

    // a = -a;
    // cout << a;

    // a += b;
    // cout << a;

    // a = a * 5 + b * 4;
    // cout << a;

    // a *= 69;
    // cout << a;

    // cout << (a == b);
    cout << ++ a;
}