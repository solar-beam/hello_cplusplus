#include <iostream>
#include <vector>

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

using namespace std;

class MQue {
public:
    int arr[50001] = {0, };
    int front = 0;
    int rear = 0;
    int size = 0;

public :
    int push(int n) {
        if (size >= 50001) return -1;
        else {
            arr[rear] = n;
            rear = (rear + 1) % 50001;
            size++;
            return n;
        }
    }
    int pop() {
        if (size < 1) return -1;
        else {
            int pos = front;
            front = (front + 1) % 50001;
            size--;
            return arr[pos];
        }
    }
    bool isEmpty() {
        return size < 1;
    }
};

vector<vector<int>> adj;
int dist[20001]; 
int visit[20001] = { 0, };
MQue q;

int PRO49189solution(int n, vector<vector<int>> results) {
    adj.resize(n, vector<int>());
    fill_n(dist, n, 10000);
    for (int i = 0; i < results.size(); i++) {
        adj[results[i][0] - 1].push_back(results[i][1] - 1);
        adj[results[i][1] - 1].push_back(results[i][0] - 1);
    }

    q.push(0);
    dist[0] = 0; 
    int maxLength = -10000;
    visit[0] = 1;
    while (!q.isEmpty()) {
        int cur = q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int item = adj[cur][i];
            if (visit[item] == 0){
                dist[item] = MIN(dist[item], dist[cur] + 1);
                maxLength = MAX(dist[item], maxLength);
                q.push(item);
                visit[item] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == maxLength) cnt++;
    }

    for (int i = 0; i < n; i++) cout << visit[i] << " ";
    return cnt;
}

int PRO49189main() {
    vector<vector<int>> in = { {3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2} };
    //cout << PRO49189solution(6, in) << endl << endl;

    vector<vector<int>> in2 = { {1,5}, {1,2}, {1,6}, {5,2}, {6,2}, {6,4}, {2,3}, {2,4}, {3,4}, {4,7}, {7,5} };
    cout << PRO49189solution(7, in2) << endl;
    return 0;
}