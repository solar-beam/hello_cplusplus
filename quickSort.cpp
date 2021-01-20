#include <iostream>
#define ARRAY_SIZE 20
#define swap(a, b) {int t=a; a=b; b=t;}
using namespace std;

int partition(int arr[], int head, int tail) {
	int x = arr[tail], cnt = head - 1, j = head;
	while (j < tail) {
		if (arr[j] <= x) {
			cnt++;
			swap(arr[cnt], arr[j]);
		}
		j++;
	}
	swap(arr[cnt + 1], arr[tail]);

	cout << "pivot : " << cnt+1 << ", head : " << head << ", tail : " << tail << endl;
	for (int i = 0; i < ARRAY_SIZE; i++) cout << arr[i] << " ";
	cout << endl;

	return cnt + 1;
}

// head <= x <= tail
void qsort(int arr[], int head, int tail) {
	if (head < tail) {
		int pivot = partition(arr, head, tail);
		qsort(arr, head, pivot - 1);
		qsort(arr, pivot + 1, tail);
	}
}

int quick_test() {
	int arr[ARRAY_SIZE] = {3,4,5,12,534,1534,31,7756,34,8,1,3,3,5,8654,342,64,35325,20,43};
	//int arr[ARRAY_SIZE] = { 0,5,2,1,4 };
	qsort(arr, 0, ARRAY_SIZE - 1);
	for (int i = 0; i < ARRAY_SIZE; i++) cout << arr[i] << " ";
	return 0;
}