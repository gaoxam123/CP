#include <bits/stdc++.h>
using namespace std;

int n, a[1005];

void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void bubble(int arr[], int n) {
    for(int i = 0; i < n; i ++) {
        for(int j = i; j < n; j ++) {
            if(arr[i] > arr[j]) swap(&arr[i], &arr[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    bubble(a, n);
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
    return 0;
}