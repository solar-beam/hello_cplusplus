#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> stk;
int rowChk[9][9] = { {0,}, };
int colChk[9][9] = { {0,}, };
int boxChk[9][9] = { {0,}, };

bool isRight(int(*vt)[9]) {
	//chk rowLine, colLine
	for (int i = 0; i < 9; i++) {
		int rowLine[9] = { 0, };
		int colLine[9] = { 0, };
		for (int j = 0; j < 9; j++) {
			if (vt[i][j] != 0) {
				rowLine[vt[i][j] - 1]++;
				if (rowLine[vt[i][j] - 1] > 1) cout << (i + 1) << "ROW ERR" << endl;;
			}
			if (vt[j][i] != 0) {
				colLine[vt[j][i] - 1]++;
				if (colLine[vt[j][i] - 1] > 1) cout << (j + 1) << "COL ERR" << endl;
			}
		}
	}
	//chk box
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int box[9] = { 0, };
			for (int k = i * 3; k < i * 3 + 3; k++) {
				for (int t = j * 3; t < j * 3 + 3; t++) {
					if (vt[k][t] != 0) {
						box[vt[k][t] - 1]++;
						if (box[vt[k][t] - 1] > 1) cout << (i + 1) << (j + 1) << "BOX ERR" << endl;
					}
				}
			}
		}
	}
	return true;
}

void getAnswer(int(*vt)[9]) {
	int result[9][9];
	memcpy(result, vt, sizeof(int) * 81);
	int pos = -1;
	while (stk.size() > 0) {
		pos = stk[stk.size() - 1]; stk.pop_back();
		int row = pos / 10, col = pos % 10;
		for (int i = 0; i < 9; i++) {
			if (rowChk[row][i] || colChk[col][i] || boxChk[row / 3 * 3 + col / 3][i]) continue;
			result[row][col] = i + 1;

			rowChk[row][i]++;
			colChk[col][i]++;
			boxChk[row / 3 * 3 + col / 3][i]++;
			getAnswer(result);

			rowChk[row][i]--;
			colChk[col][i]--;
			boxChk[row / 3 * 3 + col / 3][i]--;
		}
		stk.push_back(pos);
		return;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j > 0) cout << " ";
			cout << result[i][j];
		}
		if (i < 8) cout << endl;
	}
	//if (isRight(result)) cout << "true";
	//else cout << "false";
	exit(0);
	return;
}

int BOJ2580main()
{
	int vt[9][9] = { {0,}, };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> vt[i][j];
			if (vt[i][j] == 0) stk.push_back(i * 10 + j);
			else {
				rowChk[i][vt[i][j] - 1]++;
				boxChk[i / 3 * 3 + j / 3][vt[i][j] - 1]++;
			}
		}
	}
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			if (vt[i][j] != 0) colChk[j][vt[i][j] - 1]++;
		}
	}
	getAnswer(vt);
	return 0;
}