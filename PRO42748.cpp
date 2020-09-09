#include <iostream>
#include <vector>
#define SWAP_INT(x, y) {int t = x; x = y; y = t;}

using namespace std;

int solar_partition(vector<int>& src, int head, int tail) {
    int pivot = src[tail], i = head - 1, j = head;
    while (j < tail) {
        if (src[j] <= pivot) {
            i++;
            SWAP_INT(src[i], src[j]);
        }
        j++;
    }
    SWAP_INT(src[i + 1], src[tail]);

    return i + 1;
}

int solar_qsort(vector<int>& src, int head, int tail) {
    if (head >= tail) return 1;
    int pos = solar_partition(src, head, tail);
    solar_qsort(src, head, pos - 1);
    solar_qsort(src, pos + 1, tail);
    return 0;
}

vector<int> solution(vector<int> array, vector<vector<int>> command) {
    vector<int> answer;
    for (int tc = 0; tc < command.size(); tc++) {
        vector<int> t(command[tc][1] - command[tc][0] + 1);
        for (int i = command[tc][0] - 1, j = 0; i < command[tc][1]; i++, j++) t[j] = array[i];
        solar_qsort(t, 0, t.size() - 1);
        answer.push_back(t[command[tc][2] - 1]);
    }
    return answer;
}

int egbfzdmain() {
    vector<int> arr1 = { 1,5,2,6,3,7,4 }; vector<vector<int>> command1 = { {2,5,3},{4,4,1},{1,7,3} };
    solution(arr1, command1);

    return 0;
}