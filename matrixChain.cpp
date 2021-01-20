//BOJ 11049
#include<iostream>
#define ARRAY_SIZE 600
#define len(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

struct Matrix {
	int rownum;
	int colnum;
};

int matrixChain_TEST() {
	Matrix arr[ARRAY_SIZE];
	arr[1] = { 5, 3 };
	for (int i = 2; i < ARRAY_SIZE; i++) {
		arr[i].rownum = arr[i - 1].colnum;
		arr[i].colnum = rand() % 100;
	}

	int memo[ARRAY_SIZE];
	memo[1] = 1;
	memo[2] = arr[1].rownum * arr[1].colnum * arr[2].colnum;
	for (int i = 3; i < ARRAY_SIZE; i++) {
		int min = INT_MAX, tmp = 0;
		for (int j = 1; j < i; j++) {
			tmp = memo[j] + memo[i - j];
			min = (min < tmp) ? min : tmp;
		}
		memo[i] = min;
	}

	cout << memo[ARRAY_SIZE - 1];
	return 0;
}