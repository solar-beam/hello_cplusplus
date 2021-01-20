#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX(a, b) a>b?a:b

using namespace std;
//TODO BOJ1967
//BFS*n, 모든 정점에 대하여 거리구하기
//???, 공통조상찾기
//BFS*2, BFS로 두번탐색
//DFS, DFS로 풀기

struct node {
	int no;
	int w;

	node(int _no, int _w) {
		no = _no;
		w = _w;
	}
};

int mainBOJ1967() {
	int n; cin >> n;
	vector<vector<node>> adj(n + 1, vector<node>());
	for (int i = 0; i < n - 1; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back(node(b,w));
		adj[b].push_back(node(a,w));
	}

	int answer = 0;
	for (int cur = 1; cur < n + 1; cur++) {
		vector<int> visit(n + 1);
		vector<int> dist(n + 1);
		stack<int> stk;
		stk.push(cur);
		while (!stk.empty()) {
			int pos = stk.top(); stk.pop();
			for (int i = 0; i < adj[pos].size(); i++) {
				node& k = adj[pos][i];
				if (visit[k.no]) continue;
				dist[k.no] = MAX(dist[k.no], dist[pos] + k.w);
				visit[k.no]++;
				stk.push(k.no);
				answer = MAX(answer, dist[k.no]);
			}
		}
	}

	cout << answer;

	return 0;
}