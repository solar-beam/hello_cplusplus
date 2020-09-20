#include <iostream>
#define RED 1
#define BLACK 2

using namespace std;

template <typename T>
struct RBnode {
	int color;
	T data;
	RBnode<T>* left;
	RBnode<T>* right;
	RBnode<T>* parent;

	RBnode(char c, T d, RBnode* l, RBnode* r, RBnode* p) {
		color = c;
		data = d;
		left = l;
		right = r;
		parent = p;
	}

};

template <typename T>
struct RBtree {
	RBnode<T>* root;

	RBtree() {
		root = NULL;
	}

	RBtree(T data = 0) {
		root = new RBnode<T>(BLACK, data, NULL, NULL, NULL);
	}

	int getColor(RBnode<T>* node){
		if (node == NULL) return BLACK;
		else return node->color;
	}

	void setColor(RBnode<T>* node, int color) {
		if (node == NULL) return;
		node->color = color;
	}

	void traverse(RBnode<T>* cur) {
		if (cur == NULL) return;
		traverse(cur->left);
		cout << cur->data << endl;
		traverse(cur->right);
	}

	void rotateLeft(RBnode<T>* node) {
		
	}

	void rotateRight(RBnode<T>* node) {

	}

	void restructureRBtree(RBnode<T>* node) {

	}

	RBnode<T>* searchNode(RBnode<T>* current, T key) {
		if (current == NULL) return NULL;
		cout << current->data << " ";
		if (key == current->data) return current;
		else if (key < current->data) searchNode(current->left, key);
		else searchNode(current->right, key);
	}

	int insertNode(RBnode<T>* node) {
		if (root == NULL) {
			root = node;
			return 0;
		}

		//INSERT IN LEAF
		RBnode<T>* parent = NULL;
		RBnode<T>* current = root;
		while (current != NULL) {
			if (current->data == node->data) {
				cout << "INSERT ERR, NODE ALREADY EXISTS" << endl;
				return -1;
			}
			else if (current->data > node->data) {
				parent = current;
				current = current->left;
			}
			else {
				parent = current;
				current = current->right;
			}
		}
		if (node->data < parent->data) parent->left = node;
		else parent->right = node;
		node->parent = parent;

		//RULE CHK, RESTRUCTURE
		restructureRBtree(node);

		return 0;
	}

	int deleteNode(T key) {
		//TODO RedBlackTree delete operation
		RBnode<T>* parent = NULL;
		RBnode<T>* current = root;
		while (current != NULL) {
			if (current->data == key) {
				//leaf node, without sub tree
				if (current->left == NULL && current->right == NULL) {
					if (parent != NULL) {
						if (parent->left == current) parent->left = NULL;
						else parent->right = NULL;
					}
					else root = NULL;
				}
				//having one sub tree
				else if (current->left == NULL || current->right == NULL) {
					RBnode<T>* successor = current->left != NULL ? current->left : current->right;
					if (parent != NULL) {
						if (parent->left == current) parent->left = successor;
						else parent->right = successor;
					}
					else root = successor;
				}
				//having two sub tree
				else {
					RBnode<T>* successor_p = current;
					RBnode<T>* successor = current->right;
					while (successor->left != NULL) {
						successor_p = successor;
						successor = successor->left;
					}
					if (successor_p->left == successor) successor_p->left = successor->right;
					else successor_p->right = successor->right;
					successor->left = current->left;
					successor->right = current->right;
				}
				delete(current);
				return 0;
			}
			else if (current->data > key) {
				parent = current;
				current = current->left;
			}
			else {
				parent = current;
				current = current->right;
			}
		}
		cout << "DELETE ERR, NODE DOSENOT EXIST" << endl;
		return -1;
		return -1;
	}
};

int main() {
	RBtree<int> t = RBtree<int>(8);
	t.insertNode(new RBnode<int>(RED,14,NULL, NULL, NULL));
	t.insertNode(new RBnode<int>(RED, 25, NULL, NULL, NULL));
	t.insertNode(new RBnode<int>(RED, 3, NULL, NULL, NULL));
	t.insertNode(new RBnode<int>(RED, 17, NULL, NULL, NULL));
	t.insertNode(new RBnode<int>(RED, 7, NULL, NULL, NULL));
	t.insertNode(new RBnode<int>(RED, 9, NULL, NULL, NULL));
	t.traverse(t.root);

	return 0;
}