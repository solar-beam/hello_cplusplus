#include <iostream>
#include <vector>
#include <string>
#define MAX(a, b) a > b ? a : b;

using namespace std;

int BOJ9252main(){
	string a, b; cin >> a >> b;
	vector<vector<int>> vc(a.size()+1, vector<int>(b.size()+1));
	vector<vector<int>> sol(a.size()+1, vector<int>(b.size()+1));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a.at(i) == b.at(j)) {
				vc[i + 1][j + 1] = vc[i][j] + 1;
				sol[i + 1][j + 1] = 1;
			}
			else {
				vc[i + 1][j + 1] = MAX(vc[i][j + 1], vc[i + 1][j]);
				if (vc[i + 1][j + 1] == vc[i][j + 1]) sol[i + 1][j + 1] = 2;
				else sol[i + 1][j + 1] = 3;
			}
		}
	}

	vector<char> out;
	for (int i = a.size(); i >= 0;) {
		for (int j = b.size(); j >= 0;) {
			switch (sol[i][j]) {
			case 0:
				i = -1; j = -1;
				break;
			case 1:
				out.push_back(a.at(i-1));
				i--; j--;
				break;
			case 2:
				i--;
				break;
			case 3:
				j--;
				break;
			}
		}
	}

	cout << vc[a.size()][b.size()] << endl;
	for (int i = out.size()-1; i >= 0; i--) cout << out.at(i);
	return 0;
}