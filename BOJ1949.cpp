#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

//http://www.secmem.org/blog/2019/02/10/TreeDP/
//https://justicehui.github.io/hard-algorithm/2019/01/18/treeDP/
//https://justicehui.github.io/ps/2019/01/05/BOJ1693/
//https://www.crocus.co.kr/636
//① 트리의 독립집합을 구성할 때, 가장 가중치가 큰 독립집합의 원소 가중치합을 구하기
//② 수행시간 : scanf() 0.798, getchar() 0.390, cin 2.051
//③ #define a>b?a:b 보다 algorithm max가 더 빠르네

using namespace std;

int people[10001];
int visitBOJ1949[10001];
vector<vector<int>> adjBOJ1949;

int traverse(int cur, int state) {
	visitBOJ1949[cur] = 1;

	int result = 0;
	for (int i = 0; i < adjBOJ1949[cur].size(); i++) {
		int v = adjBOJ1949[cur][i];
		if (visitBOJ1949[v]) continue;

		if (state == 1) result += traverse(v, 0);
		else result += max(traverse(v, 0), traverse(v, 1) + people[v]);
	}

	visitBOJ1949[cur] = 0; //방문확인배열 미리 초기화하기
	return result;
}

int mainBOJ1949() {
	int n; scanf("%d", &n);
	adjBOJ1949 = vector<vector<int>>(n + 1);

	for (int i = 1; i < n + 1; i++) scanf("%d", &people[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		adjBOJ1949[a].push_back(b);
		adjBOJ1949[b].push_back(a);
	}

	//dp[i][j] i를 j로 했을 때, i를 루트로 하는 서브트리의 최대값
	int d = max(traverse(1, 0), traverse(1, 1) + people[1]);
	printf("%d", d);
	return 0;
}