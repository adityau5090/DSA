#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void recursion(Node* root, int level, vector<int>& res){
    if(root == NULL) return;
    if(res.size() == level) res.push_back(root->data);
    recursion(root->left, level+1, res);
    recursion(root->right, level+1, res);
}

vector<int> leftSideView(Node* root){
    vector<int> res;
    if(root == nullptr) return res;
    recursion(root, 0, res);
    return res;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);

    /*
              1
             / \
            2   3
           / \ / \
          4  5,6  7   // -> [1,2,4,8]
              / \
             8   9
    */

    vector<int> ans = leftSideView(root);

    for (auto val : ans) {
        cout << val << " ";
    }

    cout << endl;


    return 0;
}