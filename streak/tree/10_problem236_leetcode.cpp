// Lowest Common Ansestor Of A Binary Tree

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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root == nullptr) return NULL;

    if(root == p || root == q) return root;

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if(left != NULL && right != NULL){
        return root;
    }

    if(left != NULL) return left;
    return right;
}

int main() {

    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* new1 = lowestCommonAncestor(root, root->left, root->right);
    cout<<new1->val;
    
    return 0;
}