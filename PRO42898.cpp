#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

ll dd[101][101];

ll solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 0; i < puddles.size(); i++) {
        dd[puddles[i][1]][puddles[i][0]] = -1;
    }
    dd[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dd[i][j] < 0) continue;
            if (dd[i + 1][j] >= 0) dd[i + 1][j] = (dd[i + 1][j] + dd[i][j]) % 1000000007;
            if (dd[i][j + 1] >= 0) dd[i][j + 1] = (dd[i][j + 1] + dd[i][j]) % 1000000007;
        }
    }
    return dd[n][m];
}

int PRO42898main() {
    int m = 4, n = 3; vector<vector<int>> vc = { {2, 2} };
    cout << solution(m, n, vc);

    return 0;
}