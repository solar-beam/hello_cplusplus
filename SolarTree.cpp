//#include <vector>
//
//using namespace std;
//
//struct Node {
//	int data;
//	vector<Node> children;
//	Node() { data = -1; }
//	Node(int d) { data = d; }
//};
//
//struct Tree {
//	Node root;
//	int size;
//	int radius;
//
//	Tree() {
//		root = Node();
//		size = 0;
//		radius = 0;
//	}
//
//private:
//	int addNode(int parent_key, int input_key) {
//		Node p = findNode(parent_key);
//		if (p == NULL) return 1;
//		Node c = Node(input_key);
//		p.children.push_back(c);
//		return 0;
//	}
//
//	Node findNode(int key) {
//
//	}
//
//};