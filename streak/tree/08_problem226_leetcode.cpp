// Invert Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

void invertTree(Node* root){
    if(root == nullptr) return;

    invertTree(root->left);
    invertTree(root->right);

    swap(root->left, root->right);
}

int main() {

    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    invertTree(root);

    return 0;
}