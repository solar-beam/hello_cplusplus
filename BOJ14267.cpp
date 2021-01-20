#include <iostream>
#include <vector>

//TODO BOJ14267
using namespace std;

class TreeNode {
public:
	int num;
	unsigned long long compliment;
	vector<TreeNode*> sub;
};

class SolStack {
public:
	int size = 0;
	int arr[100000];
	void push(int n) {
		arr[size++] = n;
	}
	int pop() {
		return arr[--size];
	}
	bool isFull() {
		return size >= 100000;
	}
	bool isEmpty() {
		return size == 0;
	}
};

SolStack s;
TreeNode* arr[100000];
int BOJ14267main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		arr[i] = new TreeNode;
		arr[i]->num = i;
		arr[i]->compliment = 0;
		int t; cin >> t;
		if (t > 0) {
			arr[t - 1]->sub.push_back(arr[i]);
		}
	}
	for (int i = 0; i < m; i++) {
		int idx, w; cin >> idx >> w;
		arr[idx - 1]->compliment = w;
	}

	s.push(0);
	unsigned long long w = 0;
	while (!s.isEmpty()) {
		TreeNode* cur = arr[s.pop()];
		w = cur->compliment;
		for (int k = 0; k < cur->sub.size(); k++) {
			cur->sub[k]->compliment += w;
			s.push(cur->sub[k]->num);
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << arr[i]->compliment;
	}
	return 0;
}