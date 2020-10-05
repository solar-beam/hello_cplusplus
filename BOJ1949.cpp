#include <iostream>
#include <vector>

using namespace std;

//NODE in 1..N, EDGE is below N-1, 무방향그래프, 모든마을은 연결되어있음
//1. 우수마을로 선정된 마을주민 수의 총합을 최대로
//2. 우수마을끼리는 서로 인접해 있을 수 없음
//3. 우수마을로 선정되지 못한 마을은 적어도 하나의 우수마을과 인접해 있어야함

struct BOJ1949node {
	int no;
	int population;
	vector<BOJ1949node*> adj;

	BOJ1949node(int n) {
		no = n;
		population = -1;
		adj = vector<BOJ1949node*>();
	}
};

vector<int> results;
vector<BOJ1949node*> node;

int allVisited(vector<int>& v) {
	int sum = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == 0) return 0;
		else if (v[i] == 1) sum += node[i]->population;
	}
	return sum;
}

int num = 1;
void brute_force(vector<BOJ1949node*> &node, vector<int> visited, int cur, int state) {
	visited[cur] = state;
	cout << "VISIT" << cur << ", STATE : " << state << endl;
	int a = allVisited(visited);
	if (a > 0) {
		results.push_back(a);
		cout << "#" << num++ << " " << a << endl;
		return;
	}

	vector<int> states;
	if (state < 0) states = { 1, -1 };
	else states = { 1 };

	for (int i = 0; i < node[cur]->adj.size(); i++) {
		int c = node[cur]->adj[i]->no;
		for (int j = 0; j < states.size(); j++) {
			if (visited[c] != 0) continue;
			brute_force(node, visited, c, states[j]);
		}
	}
}

int main() {
	int n; cin >> n; node.resize(n + 1);
	vector<int> visited(n + 1);

	for (int i = 1; i <= n; i++) {
		node[i] = new BOJ1949node(i);
		cin >> node[i]->population;
	}
	for (int edge = 0; edge < n - 1; edge++) {
		int a, b; cin >> a >> b;
		node[a]->adj.push_back(node[b]);
		node[b]->adj.push_back(node[a]);
	}

	//only node reference variable
	node[0] = new BOJ1949node(0);
	node[0]->adj.push_back(node[1]);
	brute_force(node, visited, 0, -1);

	int max = -1;
	for (int i = 0; i < results.size(); i++) {
		if (max > results[i]) max = results[i];
	}
	cout << max;

	return 0;
}