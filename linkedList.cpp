#include<iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* head;
	Node* tail;
};

//N에 선행노드 추가
void addHead(Node* n, int d) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	try {
		if (newNode == NULL)throw "memory lackage error";
		newNode->data = d;
		newNode->head = n->head;
		newNode->tail = n;
		n->head = newNode;
		if (newNode->head != NULL) newNode->head->tail = newNode;
	}
	catch (string err) {
		cout << err << endl;
	}
}

void addTail() {/*반대로 하면 된다*/}

//N의 선행노드 삭제
void removeHead(Node* n) {
	n->head = NULL;
}

void removeTail() {/*반대로 하면 된다*/ }

void show(Node* n, bool flag) {
	if (flag) { //앞으로
		Node* currentNode = n;
		while (currentNode!=NULL) { //자기자신도 출력해야해서
			cout << currentNode->data << " ";
			currentNode = currentNode->head;
		}
	}
	else { //뒤로출력
		cout << "잘된다";
	}
}

void showAll(Node* n) {
	Node* currentNode = n;
	while (currentNode->head!=NULL) { //맨앞으로가기
		currentNode = currentNode->head;
	}
	show(currentNode, 0);
}

int ll_test() {
	Node* nh = (Node*)malloc(sizeof(Node));
	try{
		if (nh == NULL) throw "memory lackage error";
		nh->data = 0;
		nh->head = NULL;
		nh->tail = NULL;
	}
	catch (string err) {
		cout << err << endl;
	}

	show(nh, 1); cout << endl;

	addHead(nh, 1);
	addHead(nh, 10);
	addHead(nh, 100);
	addHead(nh, 10000);
	addHead(nh, 100000000);
	show(nh, 1); cout << endl;

	addHead(nh, 9);
	addHead(nh, 999);
	addHead(nh, 99999);
	addHead(nh, 999999999);
	show(nh, 1); cout << endl;
	show(nh, 0); cout << endl;
	showAll(nh);

	return 0;
}