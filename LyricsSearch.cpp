//https://programmers.co.kr/learn/courses/30/lessons/60060
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    char data;
    vector<Node*> child;
    int count;

    Node(char c) {
        data = c;
        count = 0;
    }
};

struct Tree {
    Node* root;
    //int count;
    //vector<vector<Node*>> level; //Aho-CorasickÂü°í

    Tree() {
        root = new Node(NULL);
        root->data = NULL;
        //count = 0;
    }

    void insert(string str) {
        Node* cur = root;
        int idx = 0;
        while (idx < str.length()) {
            //cout << str.at(idx) << " ";
            Node* past = cur;
            cur->count++;
            bool found = false;
            for (int i = 0; i < cur->child.size(); i++) {
                if (cur->child[i]->data == str.at(idx)) {
                    found = true;
                    cur = cur->child[i];
                    break;
                }
            }
            if (!found) {
                cur->child.push_back(new Node(str.at(idx)));
                cur = cur->child[cur->child.size() - 1];
            }
            idx++;
        }
        //count++;
        //cout << endl;
    }

    int search(string str) {
        int q = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.at(i) == '?') break;
            q++;
        }

        //find branch
        Node* cur = root;
        int idx = 0, cnt = 0;
        while (idx < q) {
            bool found = false;
            for (int i = 0; i < cur->child.size(); i++) {
                if (cur->child[i]->data == str.at(idx)) {
                    cur = cur->child[i];
                    found = true;
                    break;
                }
            }
            if (!found) return 0;
            idx++;
        }

        //count leaf-node
        /*idx = 0, count = 0;
        stack<pair<Node*, int>> stk;
        stk.push(make_pair(cur, q - 1));
        while (!stk.empty() && idx < str.length()) {
            pair<Node*, int> pop = stk.top(); stk.pop();
            if (pop.second == str.length() - 1) cnt++;
            else for (int i = 0; i < pop.first->child.size(); i++) {
                stk.push(make_pair(pop.first->child[i], pop.second + 1));
            }
        }*/

        return cur->count;
    }

};


Tree tree[100000];
Tree tree_inverse[100000];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < 100000; i++) {
        tree[i] = Tree();
        tree_inverse[i] = Tree();
    }

    for (int i = 0; i < words.size(); i++) {
        string& str = words[i];
        int len = str.length();
        tree[len - 1].insert(str);
        reverse(str.begin(), str.end());
        tree_inverse[len - 1].insert(str);
    }

    for (int i = 0; i < queries.size(); i++) {
        string& str = queries[i];
        int len = str.length();
        if (str.at(0) == '?') {
            reverse(str.begin(), str.end());
            answer.push_back(tree_inverse[len - 1].search(str));
        }
        else answer.push_back(tree[len - 1].search(str));
    }

    return answer;
}

int main() {
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    vector<int> result = solution(words, queries);
    vector<int> answer = { 3, 2, 4, 1, 0 };
    bool flag = true;;

    if (result.size() == 5) {
        for (int i = 0; i < 5; i++) {
            if (answer[i] != result[i]) flag = false;
            cout << result[i] << " ";
        }
    }
    else flag = false;

    if (flag) cout << "true" << endl;
    else cout << "false" << endl;
}