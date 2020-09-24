#include <iostream>
#include <stack>

using namespace std;

template <typename T>
struct BSTnode {
	T data;
	BSTnode<T>* left;
	BSTnode<T>* right;

	BSTnode(T d) {
		data = d;
		left = NULL;
		right = NULL;
	}

	BSTnode(T d, BSTnode* l, BSTnode* r) {
		data = d;
		left = l;
		right = r;
	}

	friend ostream& operator<<(ostream& os, const BSTnode<T>& node) {
		os << "[data] " << node.data << ", ";
		if (node.left != NULL) {
			os << "[left] " << node.left->data << ", ";
		}
		if (node.right != NULL) {
			os << "[right] " << node.right->data;
		}
		return os;
	}
};

template <typename T>
struct BSTtree {
	BSTnode<T>* root;

	BSTtree(T data = 0) {
		root = new BSTnode<T>(data);
	}

	void traverse(BSTnode<T>* cur) {
		if (cur == NULL) return;
		traverse(cur->left);
		cout << cur->data << endl;
		traverse(cur->right);
	}

	BSTnode<T>* searchNode(BSTnode<T>* current, T key) {
		if (current == NULL) return NULL;
		cout << current->data << " ";
		if (key == current->data) return current;
		else if (key < current->data) searchNode(current->left, key);
		else searchNode(current->right, key);
	}

	int insertNode(BSTnode<T>* node) {
		if (root==NULL) {
			root = node;
			return 0;
		}

		BSTnode<T>* parent = NULL;
		BSTnode<T>* current = root;
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
		return 0;
	}

	int deleteNode(T key) {
		BSTnode<T>* parent = NULL;
		BSTnode<T>* current = root;
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
					BSTnode<T>* successor = current->left!=NULL ? current->left : current->right;
					if (parent != NULL) {
						if (parent->left == current) parent->left = successor;
						else parent->right = successor;
					}
					else root = successor;
				}
				//having two sub tree
				else { 
					BSTnode<T>* successor_p = current;
					BSTnode<T>* successor = current->right;
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
	}

};

int _testBTS() {

	BSTtree<int> t = BSTtree<int>(8);
	t.insertNode(new BSTnode<int>(14));
	t.insertNode(new BSTnode<int>(25));
	t.insertNode(new BSTnode<int>(3));
	t.insertNode(new BSTnode<int>(17));
	t.insertNode(new BSTnode<int>(7));
	t.insertNode(new BSTnode<int>(9));
	t.traverse(t.root);
	t.deleteNode(-1);
	t.traverse(t.root);
	t.deleteNode(7);
	t.deleteNode(9);
	t.deleteNode(0);
	t.traverse(t.root);

	return 0;
}