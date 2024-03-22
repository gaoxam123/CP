#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
void swap (int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
class Heap {
	int *heap;
	int cap;
	int sz;
	public:
		Heap(int cap);
		void Heapify(int );
		int par(int i) {
			return (i - 1) / 2;
		}
		int left(int i) {
			return (2 * i + 1);
		}
		int right(int i) {
			return (2 * i + 2);
		}
		int extract();
		void replace(int i, int val);
		int get() {
			return heap[0];
		}
		void destroy(int i);
		void insert(int k);
};
Heap::Heap(int capacity) {
	sz = 0;
	cap = capacity;
	heap = new int[cap];
}
void Heap::insert(int k) {
	if (sz == cap) return;
	sz ++;
	int i = sz - 1;
	heap[i] = k;
	while (i != 0 && heap[par(i)] < heap[i]) {
		swap(&heap[i], &heap[par(i)]);
		i = par(i);	
	}
}
void Heap::replace(int i, int val) {
	heap[i] = val;
	while (i != 0 && heap[par(i)] < heap[i]) {
		swap(&heap[i], &heap[par(i)]);
		i = par(i);	
	}
}
int Heap::extract() {
	if (sz <= 0) return -1e9;
	if (sz == 1) {
		sz --;
		return heap[0];
	}
	int root = heap[0];
	heap[0] = heap[sz - 1];
	sz --;
	Heapify(0);
	return root;
}
void Heap::destroy(int i) {
	replace(i, 1e9);
	extract();
}
void Heap::Heapify(int i) {
	int l = left(i);
	int r = right(i);
	int ans = i;
	if (l < sz && heap[l] > heap[i]) ans = l;
	if (r < sz && heap[r] > heap[ans]) ans = r;
	if (ans != i) {
		swap(&heap[i], &heap[ans]);
		Heapify(ans);
	}
}
int main() {
	cin >> n;
	Heap h(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		h.insert(a[i]);
	}
	return 0;		
}