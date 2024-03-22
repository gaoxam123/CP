#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i ++) L[i] = a[i + l];
    for (int i = 0; i < n2; i ++) R[i] = a[i + m + 1];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i ++;
            k ++;
        }
        else {
            arr[k] = R[j];
            j ++;
            k ++;
        }
    }
    while(i < n1) {
        arr[k] = L[i];
        k ++;
        i ++;
    }
    while(j < n2) {
        arr[k] = R[j];
        k ++;
        j ++;
    }
}

void mergesort(int arr[], int l, int r) {
    if(l >= r) return;
    int mid = l + r >> 1;
    mergesort(a, l , mid);
    mergesort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    mergesort(a, 0, n - 1);
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
    return 0;
}