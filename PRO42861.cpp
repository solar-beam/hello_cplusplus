#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortMethod(const vector<int>& v1, const vector<int>& v2) {
    return v1[2] < v2[2];
}

inline bool allVisited(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i]==0 || v[i] != v[i - 1]) return false;
    }
    return true;
}

int PRO42861solution(int n, vector<vector<int>> cost) {
    sort(cost.begin(), cost.end(), sortMethod);
    vector<int> visit(n);
    int pos = 0, answer = 0, gId = 1;
    while (!allVisited(visit) && pos < cost.size()) {
        if (visit[cost[pos][0]] || visit[cost[pos][1]]) {
            //avoid cycle
            if (visit[cost[pos][0]] == visit[cost[pos][1]]) {
                //cout << pos << "는 거른다." << endl;
                pos++;
                continue;
            }
            //union group
            int t = visit[cost[pos][0]] > visit[cost[pos][1]] ? visit[cost[pos][0]] : visit[cost[pos][1]];
            if (visit[cost[pos][0]] == 0) visit[cost[pos][0]] = t;
            else if (visit[cost[pos][1]] == 0) visit[cost[pos][1]] = t;
            else {
                vector<int> temp(n);
                temp.assign(visit.begin(), visit.end());
                for (int i = 0; i < visit.size(); i++) {
                    if (visit[i] == visit[cost[pos][0]] || visit[i] == visit[cost[pos][1]]) temp[i] = t;
                }
                visit.assign(temp.begin(), temp.end());
            }
        }
        else {
            //set group
            visit[cost[pos][0]] = gId;
            visit[cost[pos][1]] = gId;
            gId++;
        }
        answer += cost[pos][2];
        //cout << pos << "는 포함한다." << endl;
        pos++;
    }

    cout << answer << endl;;
    return answer;
}

int PRO42861main() {
    /*vector<vector<int>> in{ {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    if (PRO42861solution(4, in) == 4) cout << "#1 CORRECT" << endl;
    else cout << "#1 WRONG" << endl;

    vector<vector<int>> in2{ {0,1,1},{3,1,1},{0,2,2},{0,3,2},{0,4,100} };
    if (PRO42861solution(5, in2) == 104) cout << "#2 CORRECT" << endl;
    else cout << "#2 WRONG" << endl;

    vector<vector<int>> in3{ {0,1,1},{2,3,1},{3,4,2},{1,2,2},{0,4,100} };
    if (PRO42861solution(5, in3) == 6) cout << "#3 CORRECT" << endl;
    else cout << "#3 WRONG" << endl;

    vector<vector<int>> in4{ {0,1,1},{3,4,1},{1,2,2},{2,3,4} };
    if (PRO42861solution(5, in4) == 8) cout << "#4 CORRECT" << endl;
    else cout << "#4 WRONG" << endl;*/

    vector<vector<int>> in5{ {5,0,10}, {2,3,12}, {1,6,14}, {1,2,16}, {3,6,18}, {3,4,22}, {4,6,24}, {0,1,28}, {4,5,25} };
    if (PRO42861solution(7, in5) == 99) cout << "#5 CORRECT" << endl;
    else cout << "#5 WRONG" << endl;

    return 0;
}
