#include <string>
#include <vector>
#include <iostream>
#define ull unsigned long long

using namespace std;

ull arr[1000000][20];
void _arr_init() {
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 20; j++) arr[i][j] = 0;
	}
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	//_arr_init();

	for (int i = 0; i < phone_book.size(); i++) {
		int hash = 0;
		for (int j = 0; j < phone_book[i].size(); j++) {
			int cur = phone_book[i][j] - '0';
			hash = (hash * 31 + cur);
			arr[i][j] = hash;
		}
	}
	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = 0; j < phone_book.size(); j++) {
			if (i == j) continue;
			if (arr[i][phone_book[i].size() - 1] == arr[j][phone_book[i].size() - 1]) {
				j = phone_book.size();
				i = phone_book.size();
				answer = false;
			}
		}
	}

	//if (answer) cout << "true" << endl;
	//else cout << "false" << endl;
	return answer;
}

int asdfmain() {
	vector<string> tc1 = { "119", "97674223", "1195524421" };
	solution(tc1);
	vector<string> tc2 = { "123", "456", "789" };
	solution(tc2);
	vector<string> tc3 = { "12", "123", "1235", "567", "88" };
	solution(tc3);

	return 0;
}