#include <iostream>
#include <vector>
#define BTREE_DEGREE 4

using namespace std;

struct Bnode {
	vector<int> data;
	bool isLeaf;
	vector<Bnode> children;

	Bnode() {
		data.resize(BTREE_DEGREE);
		isLeaf = true;
		children.resize(BTREE_DEGREE + 1);
	}
};

struct Btree {
	Bnode root;

	Btree() {
		root = Bnode();
	}


};