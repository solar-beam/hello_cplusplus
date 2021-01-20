// ref : https://twpower.github.io/139-hash-table-implementation-in-cpp
// 사실 cpp에는 이미 map이 있는데 한번 구현해보는 데 의의가 있다.
#include<iostream>
#include<string>
#include <map>
using namespace std;

struct Node {
	char key[100];
	int value;
	Node* next;
};

int hash_test() {
	return 0;

	map<string, int> m;
}