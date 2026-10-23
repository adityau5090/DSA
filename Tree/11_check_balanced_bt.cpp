// Check Balanced Binary Tree

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

int checkHeight(Node* root){
    if(root == NULL) return false;

    int lh = checkHeight(root->left);
    if(lh == -1) return -1;
    int rh = checkHeight(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(Node* root){
    return checkHeight(root) != -1;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right= new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int ans = isBalanced(root);

    if(ans == 1) cout<<"Balanced BT";
    else cout<<"Flase";

    return 0;
}