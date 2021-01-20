//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define INF 1000000
//#define MIN(a, b) a<b?a:b
//#define MAX(a, b) a>b?a:b
//
//using namespace std;
//
////TODO BOJ2610
//class Node2610 {
//public:
//	int ID, maxPathCost;
//
//	Node2610(int a, int b) {
//		ID = a;
//		maxPathCost = b;
//	}
//
//	int compareTo(Node2610 target) {
//		return maxPathCost - target.maxPathCost;
//	}
//};
//
//
//int N = 0, M = 0, X = 0, cnt2610 = 0;
//vector<int> leaderList;
//vector<vector<int>> dist;
//
//void floydWarshall();
//void findCommitteeInfo();
//int electLeader(vector<int> connectedVertexList);
//
//int main2610() {
//	cin >> N >> M;
//	dist.resize(N+1, vector<int>(N+1, 0));
//	for (int i = 0; i <= N; i++) {
//		for (int j = 0; j <= N; j++) {
//			if (i == j) continue;
//			dist[i][j] = INF;
//		}
//	}
//
//	for (int i = 0; i < M; i++) {
//		int u, v; cin >> u >> v;
//		dist[u][v] = 1;
//		dist[v][u] = 1;
//	}
//
//	floydWarshall();
//	findCommitteeInfo();
//
//	cout << cnt2610 << endl;
//	sort(leaderList.begin(), leaderList.end());
//	for (int i = 0; i < leaderList.size(); i++) {
//		cout << leaderList[i] << endl;
//		//cout << leaderList[i] << " ";
//	}
//
//	return 0;
//}
//
//
//void floydWarshall() {
//	for (int k = 1; k <= N; k++) {
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= N; j++) {
//				dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
//			}
//		}
//	}
//}
//
//void findCommitteeInfo() {
//	vector<bool> visited(N + 1);
//	vector<int> connectedVertexList;
//
//	for (int i = 1; i <= N; i++) {
//		if (!visited[i]) {
//			cnt2610++;
//			visited[i] = true;
//			connectedVertexList.push_back(i);
//			for (int j = 1; j <= N; j++) {
//				if (dist[i][j] != INF && i != j) {
//					connectedVertexList.push_back(j);
//					visited[j] = true;
//				}
//			}
//			leaderList.push_back(electLeader(connectedVertexList));
//			connectedVertexList.clear();
//		}
//	}
//}
//
//int electLeader(vector<int> connectedVertexList) {
//	queue<Node2610> pq;
//	for (int i = 0; i < connectedVertexList.size(); i++) {
//		int maxPathCost = INF * -1;
//		int v = connectedVertexList[i];
//		for (int j = 1; j <= N; j++) {
//			if (dist[v][j] != INF && v != j) {
//				maxPathCost = MAX(maxPathCost, dist[v][j]);
//			}
//		}
//		pq.push(Node2610(v, maxPathCost));
//	}
//	return pq.front().ID;
//}
