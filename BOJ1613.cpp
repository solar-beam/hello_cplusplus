#include <iostream>
#include <vector>
#include <stack>

//TODO BOJ1613 시간초과

using namespace std;

struct BOJ1613Node {
	int data;
	vector<BOJ1613Node*> parent;
	vector<BOJ1613Node*> children;

	BOJ1613Node(int d) { 
		data = d;
		parent;
		children;
	}
};

vector<BOJ1613Node*> list;

int searchHistory(int src, int dest) {
	cout << "## ";

	//search through children return -1
	stack<int> cstack;
	for (int i = 0; i < list[src]->children.size(); i++) {
		int t = list[src]->children[i]->data;
		cstack.push(t);
	}
	while (!cstack.empty()) {
		if (dest == cstack.top()) {
			//cout << " ##";
			return -1;
		}
		int s = cstack.top(); cstack.pop();
		//cout << s << " ";
		for (int i = 0; i < list[s]->children.size(); i++) {
			int t = list[s]->children[i]->data;
			cstack.push(t);
		}
	}

	//search through parents return 1
	stack<int> pstack;
	for (int i = 0; i < list[src]->parent.size(); i++) {
		int t = list[src]->parent[i]->data;
		pstack.push(t);
	}
	while (!pstack.empty()) {
		if (dest == pstack.top()) {
			//cout << " ##";
			return 1;
		}
		int s = pstack.top(); pstack.pop();
		//cout << s << " ";
		for (int i = 0; i < list[s]->parent.size(); i++) {
			int t = list[s]->parent[i]->data;
			pstack.push(t);
		}
	}

	//return 0
	//cout << " ##";
	return 0;
}

int mainBOJ1613() {
	int n, k, s; cin >> n >> k;
	list.push_back(new BOJ1613Node(0));
	for (int i = 1; i <= n; i++) list.push_back(new BOJ1613Node(i));

	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		list[a]->children.push_back(list[b]);
		list[b]->parent.push_back(list[a]);
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b; cin >> a >> b;
		cout << searchHistory(a, b) << endl;
	}
	return 0;
}