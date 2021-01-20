//ref: introduction to algorithm pseudo code
#include <iostream>
#define HEAP_SIZE 15
#define parent(i) i>>1
#define left(i) i<<1
#define right(i) (i<<1)+1
#define swap(a,b) {int t=a; a=b; b=t;}
using namespace std;

struct heap {
	int arr[HEAP_SIZE];
	int value[HEAP_SIZE]; //priority que, arr : work load = value : work
	int length=0;
	int heap_size=0;
};

/** ##HEAP_SORT */
//compare idx node with child node, 
//change idx node to max value node
void max_heapify(struct heap* h, int idx) {
	int l = left(idx), r = right(idx), max=-1;
	cout << "l : " << l << ", r : " << r << ", m : " << max << endl;
	
	if (l <= h->heap_size && h->arr[l] > h->arr[idx]) max = l;
	else max = idx;
	if (r <= h->heap_size && h->arr[r] > h->arr[max]) max = r;

	if (max != idx) {
		cout << "swap(" << h->arr[idx] << ", " << h->arr[max] << ")" << endl;
		swap(h->arr[idx], h->arr[max]);
		max_heapify(h, max);
	}
}

//max heap's parent node is same or larger than child node
//children nodes are not related to its size comparison
void build_max_heap(struct heap* h) {
	h->heap_size = h->length;
	for (int i = h->length / 2; i >= 1; i--) {
		max_heapify(h, i);
	}
}

//to set max value as arrray last eleement
void heap_sort(struct heap* h) {
	build_max_heap(h);
	for (int i = (h->length); i >= 2; i--) {
		swap(h->arr[1], h->arr[i]);
		h->heap_size--;
		max_heapify(h, 1);
	}
}

/** ##PRIORITY QUE */

int heap_extract_max(struct heap* h) {
	//could replace it to try/catch
	if (h->heap_size < 1) {
		cout << "heap underflow" << endl;
		return -1;
	}
	int max = h->arr[1];
	h->arr[1] = h->arr[h->heap_size];
	(h->heap_size)--;
	max_heapify(h, 1);
	return max;
}

int max_heap_delete(struct heap* h) {
	return heap_extract_max(h);
}

void heap_increase_key(struct heap* h, int idx, int key) {
	if (key < h->arr[idx]) {
		cout << "smaller than current value" << endl;
		return;
	}
	h->arr[idx] = key;
	//[idx...root], if key<current -> swap[idx...leaf]
	while (idx > 1 && h->arr[parent(idx)] < h->arr[idx]){
		swap(h->arr[idx], h->arr[parent(idx)]);
		idx = parent(idx);
	}
}

void max_heap_insert(struct heap* h, int key) {
	(h->heap_size)++;
	h->arr[h->heap_size] = -2147483648;
	heap_increase_key(h, h->heap_size, key);
}


int heap_maximum(struct heap* h) {
	return h->arr[1];
}

//to check whether it is max heap
//to set heap_size
bool is_max_heap(struct heap* h) {
	bool flag = true;
	for (int i = h->length; i > 1; i--) {
		if (h->arr[i] > h->arr[parent(i)]) {
			cout << "FALSE, arr[" << i << "] : " << h->arr[i] << ", arr[p] : " << h->arr[parent(i)] << endl;
			flag = false;
			//return false;
		}
	}
	if (flag) {
		h->heap_size = h->length;
		cout << h->heap_size << endl;
		return true;
	}
	else return false;
}

int heap_test() {
	struct heap maxh = {
		//{-1, 27, 17, 16, 13, 10, 7, 8, 3, 1, 4, 9, 1, 5, 0}, //sorted
		{-1, 1, 4, 8, 9, 27, 7, 17, 3, 16, 13, 10, 1, 5, 0}, //unsorted
		//{},
		{},
		HEAP_SIZE,
		0
	};
	struct heap* ptrh = &maxh;
	is_max_heap(ptrh);

	//max_heapify(ptrh, 1);
	//build_max_heap(ptrh);
	//heap_sort(ptrh);

	for (int i = 1; i < maxh.length; i++)cout << maxh.arr[i] << endl;;
	return 0;
}