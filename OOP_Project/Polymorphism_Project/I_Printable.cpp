#include <bits/stdc++.h>
#include "I_Printable.h"
using namespace std;

ostream &operator<<(ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}