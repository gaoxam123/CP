#include <bits/stdc++.h>
using namespace std;

int *apply_all(int *arr1, int size1, int *arr2, int size2) {
    int *res{nullptr};
    res = new int[size1 * size2];
    int k = 0;

    for(int i = 0; i < size1; i ++) {
        for (int j = 0; j < size2; j ++) {
            res[k] = arr1[i] * arr2[j];
            k ++;
        }
    }

    return res;
}

int main() {
    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    int *res = apply_all(array1, 5, array2, 3);

    for(int i = 0; i < 15; i ++) {
        cout << res[i] << " ";
    }
}