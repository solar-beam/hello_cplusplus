// ref : https://doorbw.tistory.com/43?category=677963
#include <iostream>
#include <cstdlib>
#include <time.h>
#define max(a,b) {a>b?a:b};
using namespace std;

struct Bubble{
	int t1;
	int n1;
	int t2;
	int n2;
};

//��ȭ�� : Pn = max(Pi + Rn-i), i range 1...n
//��, ����ǥ�� ���������Ѵٰ� �����Ѵ�.
int cutRod(int price[], int n) {
	if (n == 0) return 0;
	int q = INT_MIN;
	for (int i = 1; i <= n; i++) {
		q = max(q, price[i] + cutRod(price, n-i));
	}
	return q;
}

//����ϸ� Ǯ��!
int dynamicCutRod(int price[], int n) {
	try {
		int* memo = (int*)calloc(n+1, sizeof(int));
		if (memo == NULL) throw "null pointer err!! memory is full!!";
		int q;
		for (int j = 1; j <= n; j++) {
			q = INT_MIN;
			for (int i = 1; i <= j; i++) {
				q = max(q, price[i] + memo[j - i]);
			}
			*(memo + j) = q;
		}
		return *(memo + n);
		//FREE(MEMO) ���??
	}
	catch (string e) {
		cout << e << endl;
		return INT_MIN;
	}
}

Bubble timeChk(int price[], int n) {
	int start, end;
	Bubble b = {-1, -1};

	start = time(0);
	b.n1= cutRod(price, n);
	end = time(0);
	b.t1 = end - start;

	start = time(0);
	b.n2 = dynamicCutRod(price, n);
	b.t2 = end - start;

	return b;
}

int rod_test() {
	//���� �����ϴ� ������
	int price[2001];
	srand(time(NULL));
	price[0] = 0;
	for (int i = 1; i < 2001; i++) {
		int tmp;
		do {
			tmp = rand() % 10000;
		} while (tmp < price[i - 1]);
		price[i] = tmp;
	}
	
	Bubble tmp;
	cout << "Brute-force / Bottom-up" << endl;
	for (int i = 1; i < 1000; i++) {
		tmp = timeChk(price, i);
		cout << "(�ð�) n=" << i << " : " << tmp.t1 << " , " << tmp.t2 << endl;
		cout << "(���) n=" << i << " : " << tmp.n1 << " , " << tmp.n2 << endl;
	}

	return 0;
}