#include <iostream>

using namespace std;

class Bloom {
public:
	int m;
	int d;

	Bloom() : Bloom(0, 0) {}
	Bloom(int month, int date) {
		m = month;
		d = date;
	}
};

int monthlydays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Bloom flowers[100000][2];
int subs[100000] = { 0, };

int substract(Bloom o, Bloom o2) {
	int sum = 0;
	for (int i = o.m + 1; i < o2.m; i++) sum += monthlydays[i];
	if (o.m != o2.m) sum += ( (monthlydays[o.m] - o.d + 1) + o2.d);
	else sum += (o2.d - o.d);
	return sum;
}

int mainBOJ2457() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		flowers[i][0] = Bloom(a, b);
		flowers[i][1] = Bloom(c, d);
		subs[i] = substract(flowers[i][0], flowers[i][1]);
	}

	cout << endl;
	for (int i = 0; i < n; i++) cout << subs[i] << " ";
	//sort by subs in descending order
	//pick flowers until cover 3.1.~11.30.

	return 0;
}