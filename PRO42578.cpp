#include <iostream>
#include <string>
#include <vector>
#define HASHTABLE_SIZE 103049

using namespace std;

int nums[HASHTABLE_SIZE] = { 0, };

void _init_arr() {
    for (int i = 0; i < HASHTABLE_SIZE; i++) nums[i] = 0;
}

int getHash(string& key) {
    unsigned long hash = 0;
    for (int i = 0; i < key.size(); i++) {
        hash = (hash * 31 + key[i]); //rabin-carp
    }
    return hash % HASHTABLE_SIZE;
}

int solution(vector<vector<string>> clothes) {
    vector<int> keySet;
    _init_arr();

    for (int i = 0; i < clothes.size(); i++) {
        int hash = getHash(clothes[i][1]);
        if (nums[hash] == 0) keySet.push_back(hash);
        nums[hash]++;
    }

    int answer = 1;
    for (int i = 0; i < keySet.size(); i++) {
        answer *= (nums[keySet[i]]+1);
    }
    answer--;
    cout << answer << endl;
    return answer;
}

int asdddfafmain() {
    vector<vector<string>> tc1 = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };
    solution(tc1);
    vector<vector<string>> tc2 = { {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} };
    solution(tc2);
    return 0;
}