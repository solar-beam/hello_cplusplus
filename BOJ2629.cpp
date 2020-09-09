#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;
int dp[40001] = { 0, };
int temp[40001] = { 0, };
int n[30] = { 0, };
int cnt = 0;

int BOJ2629main() {
    int wn; cin >> wn;
    vector<int> w(wn);
    for (int i = 0; i < wn; i++) cin >> w[i];
    int tcn; cin >> tcn;
    vector<int> tc(tcn);
    dp[0] = 1;
    for (int i = 0; i < tcn; i++)cin >> tc[i];

    for (int i = 0; i < wn; i++) {
        memcpy(temp, dp, sizeof(int) * 40000);
        for (int j = 0; j < 15001; j++) {
            if (dp[j] > 0) {
                cout << i << ", " << j << "에서 " << abs(j - w[i]) << ", " << j + w[i] << "체크" << endl;
                temp[abs(j - w[i])]++;
                temp[j + w[i]]++;
            }
        }
        memcpy(dp, temp, sizeof(int) * 40000);
    }

    for (int i = 0; i < tcn; i++) {
        if (i != 0) cout << " ";
        if (dp[tc[i]]) cout << "Y";
        else cout << "N";
    }
    return 0;
}