#include <iostream>
#include <string>
#include <vector>
#define HASHTABLE_SIZE 103049

using namespace std;

struct Node {
	string key;
	int value;
	Node* next;
};

class StringHashTable {
private:
	Node* tb[HASHTABLE_SIZE];

public:
	int key_collision = 0;
	int hash_collision = 0;
	int nodeNum = 0;

public:
	void _init() {
		for (int i = 0; i < HASHTABLE_SIZE; i++) tb[i] = NULL;
		key_collision = 0;
		hash_collision = 0;
		nodeNum = 0;
	}

	int addNode(string& key) {
		nodeNum++;
		int pos = getHash(key);
		Node* cur;

		if (tb[pos] != NULL) {
			Node* cur = tb[pos];
			while (cur) {
				if (key == cur->key) {
					key_collision++; //동명이인
					cur->value++; 
					return -1;
				}
				else {
					if (cur->next != NULL) cur = cur->next;
					else {
						hash_collision++; //해시충돌
						cur->next = new Node; 
						cur->next->key = key;
						cur->next->value = 1;
						cur->next->next = NULL;
						return 1;
					}
				}
			}
		}
		tb[pos] = new Node; //새로운 참가자
		tb[pos]->key = key;
		tb[pos]->value = 1;
		tb[pos]->next = NULL;
		return 0;
	}

	Node* getNode(string& key) {
		int pos = getHash(key);
		Node* cur = tb[pos];
		while (cur) {
			if (key == cur->key) break;
			else if (cur->next != NULL) cur = cur->next;
		}
		return cur;
	}

	int getHash(string& key) {
		unsigned long hash = 0;
		for (int i = 0; i < key.size(); i++) {
			hash = (hash * 31 + key[i]); //rabin-carp
		}
		return hash % HASHTABLE_SIZE;
	}
};

StringHashTable st;
string solution(vector<string> participant, vector<string> completion) {
	string result = "";
	st._init();
	for (int i = 0; i < completion.size(); i++) {
		st.addNode(completion[i]);
	}
	for (int i = 0; i < participant.size(); i++) {
		Node* n = st.getNode(participant[i]);
		if (n == NULL || n->value <= 0) {
			result = participant[i];
			break;
		}
		n->value--;
	}
	return result;
}

int dfasdmain() {
	vector<string> pc0 = {}, com0 = {};
	cout << solution(pc0, com0) << endl;
	vector<string> pc1 = { "leo", "kiki", "eden" }, com1 = { "eden", "kiki" };
	cout << solution(pc1, com1) << endl;
	vector<string> pc2 = { "marina", "josipa", "nikola", "vinko", "filipa"}, com2 = { "josipa", "filipa", "marina", "nikola" };
	cout << solution(pc2, com2) << endl;
	vector<string> pc3 = { "mislav", "stanko", "mislav", "ana" }, com3 = { "stanko", "ana", "mislav" };
	cout << solution(pc3, com3) << endl;
	vector<string> pc4 = { "mislav", "stanko", "mislav", "ana" }, com4 = { "stanko", "ana", "mislav", "mislav" };
	cout << solution(pc4, com4) << endl;
	vector<string> pc5 = { "mislav", "stanko", "mislav", "ana", "ana", "ana" }, com5 = { "mislav", "stanko", "mislav", "ana", "ana" };
	cout << solution(pc5, com5) << endl;
	return 0;
}