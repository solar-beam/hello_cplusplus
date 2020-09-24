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


	RBnode(int c, T d, RBnode* l, RBnode* r, RBnode* p) {
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
	RBnode<T>* sentinel;

	RBtree() {
		sentinel = new RBnode<T>(BLACK, -1, NULL, NULL, NULL);
		root = NULL;
	}

	RBtree(T data = 0) {
		sentinel = new RBnode<T>(BLACK, -1, NULL, NULL, NULL);
		root = new RBnode<T>(BLACK, data, sentinel, sentinel, sentinel);
	}

	void traverse(RBnode<T>* cur) {
		if (cur == sentinel) return;
		traverse(cur->left);
		cout << cur->data << endl;
		traverse(cur->right);
	}

	//오른쪽으로 늘어진 사슬을 왼쪽으로 돌려 꺾음
	void rotateLeft(RBnode<T>* node) {
		RBnode<T>* downnode = node->right;

		//자식노드 전처리
		node->right = downnode->left;
		if (downnode->left != sentinel) {
			downnode->left->parent = node;
		}
		downnode->left = node;

		//부모노드설정, 위치변경
		downnode->parent = node->parent;
		if (node->parent == sentinel) {
			root = downnode;
		}
		else if (node == node->parent->left) {
			node->parent->left = node;
		}
		else node->parent->right = node;
		node->parent = downnode;

	}

	//왼쪽으로 늘어진 사슬을 오른쪽으로 돌려 꺾음
	void rotateRight(RBnode<T>* node) {
		RBnode<T>* upnode = node->parent;

		//자식노드 전처리
		upnode->left = node->right;
		if(node->right != sentinel) {
			node->right->parent = upnode;
		}
		node->right = upnode;

		//부모노드설정, 위치변경
		node->parent = upnode->parent;
		if (upnode->parent == sentinel) {
			root = node;
		}
		else if (node == node->parent->left) {
			node->parent->left = node;
		}
		else node->parent->right = node;
		upnode->parent = node;

	}

	void FIXUP(RBnode<T>* z) {
		while (z->parent->color == RED) {
			if (z->parent == z->parent->parent->left) {
				RBnode<T>* y = z->parent->parent->right;
				//CASE1
				if (y->color == RED) {
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				//CASE2
				else if (z == z->parent->right) {
					z = z->parent;
					rotateLeft(z);
				}
				//CASE3
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rotateRight(z);
			}
			else {
				RBnode<T>* y = z->parent->parent->left;
				//CASE1
				if (y->color == RED) {
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				//CASE2
				else if (z == z->parent->left) {
					z = z->parent;
					rotateRight(z);
				}
				//CASE3
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rotateLeft(z);
			}
		}
		root->color = BLACK;
	}

	RBnode<T>* searchNode(RBnode<T>* current, T key) {
		if (current == NULL) return NULL;
		cout << current->data << " ";
		if (key == current->data) return current;
		else if (key < current->data) searchNode(current->left, key);
		else searchNode(current->right, key);
	}

	int insertNode(RBnode<T>* z) {
		RBnode<T>* y = sentinel;
		RBnode<T>* x = root;
		while (x != sentinel) { //z키값 범위에 맞는 위치를 리프노드까지 탐색
			y = x;
			if (z->data < x->data) x = x->left;
			else x = x->right;
		}
		z->parent = y; //y는 z의 부모노드
		if (y == sentinel) root = z;//루트거나 왼쪽,오른쪽자식
		else if (z->data < y->data) y->left = z;
		else y->right = z;
		z->left = sentinel;
		z->right = sentinel;
		z->color = RED;

		//RULE CHK, RESTRUCTURE
		FIXUP(z);
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
	cout << "TREE" << endl;
	t.insertNode(new RBnode<int>(RED,14, t.sentinel, t.sentinel, t.sentinel));
	cout << "1" << endl;
	t.insertNode(new RBnode<int>(RED, 25, t.sentinel, t.sentinel, t.sentinel));
	cout << "2" << endl;
	t.insertNode(new RBnode<int>(RED, 3, t.sentinel, t.sentinel, t.sentinel));
	cout << "3" << endl;
	t.insertNode(new RBnode<int>(RED, 17, t.sentinel, t.sentinel, t.sentinel));
	cout << "4" << endl;
	t.insertNode(new RBnode<int>(RED, 7, t.sentinel, t.sentinel, t.sentinel));
	cout << "5" << endl;
	t.insertNode(new RBnode<int>(RED, 9, t.sentinel, t.sentinel, t.sentinel));
	cout << "6" << endl;
	t.traverse(t.root);

	return 0;
}