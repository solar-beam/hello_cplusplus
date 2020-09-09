#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#define HASHTABLE_SIZE 100000//https://www.di-mgt.com.au/primes1000.html
#define KEY_MAX_LENGTH 100
#define LINE_MAX_LENGTH 1000
#define VALUE_MAX_SIZE 1000
#define VECTOR_MAX_SIZE 1073741823/4

using namespace std;

struct Node {
	char key[KEY_MAX_LENGTH];
	int value;
	Node* next = NULL;
};

class SolarHashTable {
private:
	Node* tb[HASHTABLE_SIZE];

public:
	int err = 0;
	int collision = 0;
	int nodeNum = 0;

public:
	void _init() {
		for (int i = 0; i < HASHTABLE_SIZE; i++) tb[i] = NULL;
		err = 0;
		collision = 0;
	}

	int _randTextTest() {
		srand(time(NULL));
		for (int i = 0; i < HASHTABLE_SIZE; i++) {
			char randKey[KEY_MAX_LENGTH];
			for (int k = 0; k < KEY_MAX_LENGTH - 1; k++) {
				randKey[k] = rand()%26 + 97; //ASCII
			}
			randKey[KEY_MAX_LENGTH - 1] = '\0';
			int randValue = rand()% VALUE_MAX_SIZE + 1;
			addNode(randKey, randValue);
		}
		return 0;
	}

	int _fileTextTest() {
		ifstream fileReader;
		fileReader.open("bible.txt");
		if (fileReader.is_open()) {
			srand(time(NULL));
			while (!fileReader.eof()) {
				//if (nodeNum > HASHTABLE_SIZE) break;
				//istream style
				char buffer[LINE_MAX_LENGTH];
				fileReader.getline(buffer, LINE_MAX_LENGTH);
				//cout << "cursor : " << buffer << endl;
				
				//std style
				//string buffer;
				//getline(fileReader, buffer);
				int front = 0, rear = 0;
				bool flag = true;
				while (buffer[rear] != '\0') {
					if (buffer[rear] == '\t') {
						rear++;
						front = rear;
						continue;
					}
					if (buffer[rear] == ' ') {
						char token[KEY_MAX_LENGTH];
						int i = 0;
						while (front < rear) {
							token[i] = buffer[front];
							i++, front++;
						}
						token[i] = '\0';
						//int v = rand()% VALUE_MAX_SIZE + 1;
						int v = 0;
						addNode(token, v);
						rear++;
						front = rear;
					}
					else {
						rear++;
					}
				}

			}
		}
		return 0;
	}

	bool keyCmp(char(&o1)[KEY_MAX_LENGTH], char(&o2)[KEY_MAX_LENGTH]) {
		int i = 0;
		while (o1[i] != '\0' && o2[i] != '\0') {
			if (o1[i] != o2[i]) return false;
			i++;
		}
		if (o1[i] != '\0' || o2[i] != '\0') return false;
		return true;
	}

	void keyCpy(char(&dist)[KEY_MAX_LENGTH], char(&src)[KEY_MAX_LENGTH], int length) {
		int i = 0;
		while (src[i] != '\0' && i < length) {
			dist[i] = src[i];
			i++;
		}
		dist[i] = '\0';
	}

	int addNode(char(&key)[KEY_MAX_LENGTH], int value) {
		nodeNum++;
		int pos = getHash(key);
		Node* cur;
		//cout << "#HASHCODE : " << pos << endl;

		if (tb[pos] != NULL) {
			Node* cur = tb[pos];
			while (cur) {
				if (keyCmp(key, cur->key)) {
					err++;
					return -1;
				}
				else {
					if (cur->next != NULL) cur = cur->next;
					else {
						collision++;
						cur->next = new Node;
						keyCpy(cur->next->key, key, KEY_MAX_LENGTH);
						cur->next->value = value;
						cur->next->next = NULL;
						return 1;
					}
				}
			}
		}
		tb[pos] = new Node;
		keyCpy(tb[pos]->key, key, KEY_MAX_LENGTH - 1);
		tb[pos]->value = value;
		tb[pos]->next = NULL;
		return 0;
	}

	int delNode(char(&key)[KEY_MAX_LENGTH]) {
		//TODO
	}

	int editNode(char (&key)[KEY_MAX_LENGTH], int value) {
		Node* n = getNode(key);
		if (n == NULL) return -1;
		else {
			n->value = value;
			return 0;
		}
	}

	Node* getNode(char (&key)[KEY_MAX_LENGTH]) {
		int pos = getHash(key);
		Node* cur = tb[pos];
		while (cur) {
			if (key == cur->key) break;
			else if (cur->next != NULL) cur = cur->next;
		}
		return cur;
	}
	
	int getHash(char key[]) {
		unsigned long int hash = 0;
		int poly = 0xEDB88320;
		for (int i = 0; key[i] != '\0'; i++) {
			//hash = (((hash << 5) + hash) + key[i]);
			hash = (hash * 31 + key[i]); //rabin-carp
			//hash = (65599 * hash + key[i]); //x65599
			//poly = (poly << 1) | (poly >> (32 - 1)); hash = (int)(poly * hash + key[i]); //0xEDB88320 + 1bit Shift
		}
		hash %= HASHTABLE_SIZE;
		return hash;
	}
};

SolarHashTable st;
int stmain() {
	time_t start, end;
	double result;

	start = time(NULL);
	st._init();
	st._randTextTest();
	cout << "# RANDON TEXT TEST" << endl;
	cout << "- NODE      : " << st.nodeNum << endl;
	cout << "- COLLISION : " << st.collision << endl;
	cout << "- ERROR     : " << st.err << endl;
	end = time(NULL);
	result = (double)(end - start);
	cout << "¡Ø " << result << "ms" << endl;
	
	start = time(NULL);
	st._init();
	st._fileTextTest();
	cout << endl << "# FILE TEXT(BIBLE) TEST" << endl;
	cout << "- NODE      : " << st.nodeNum << endl;
	cout << "- COLLISION : " << st.collision << endl;
	cout << "- ERROR     : " << st.err << endl;
	end = time(NULL);
	result = (double)(end - start);
	cout << "¡Ø " << result << "ms" << endl;

	return 0;
}