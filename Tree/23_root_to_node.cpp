#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

bool getPath(Node* root, vector<int> & arr, int x){
    if(!root) return false;

    arr.push_back(root->val);
    if(root->val == x) return true;

    if(getPath(root->left,arr,x) || getPath(root->right, arr,x)) return true;

    arr.pop_back();
    return false;
}

vector<int> rootToNode(Node* root, int x){
    vector<int> arr;
    if(root == nullptr) return arr;
    getPath(root, arr, x);
    return arr;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans = rootToNode(root, 7);

    for (auto val : ans) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}