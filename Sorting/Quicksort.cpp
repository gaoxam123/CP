#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

void swap(int *x, int *y) {
    int z = *x; 
    *x = *y;
    *y = z;
}

int partition(int arr[], int l, int r) {
    int pi = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j ++) {
        if(arr[j] < pi) {
            i ++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quicksort(int arr[], int l, int r){
    if(l >= r) return;
    int pi = partition(arr, l, r);
    quicksort(arr, l, pi - 1);
    quicksort(arr, pi + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    quicksort(a, 0, n - 1);
    for(int i = 0; i < n; i ++) cout << a[i] << " ";
    return 0;
}