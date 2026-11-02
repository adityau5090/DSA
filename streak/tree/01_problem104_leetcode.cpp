// Maximum Depth Of Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

int maxDepth(Node* root){

    if(root == NULL) return 0;

    int L = maxDepth(root->left);
    int R = maxDepth(root->right);

    return 1 + max(L,R);
}

int main() {

    Node root = Node(3);
    root.left = new Node(9);
    root.right = new Node(20);
    root.right->left = new Node(15);
    root.right->right = new Node(7);

    cout<<"Max Depth : "<<maxDepth(&root);

    return 0;
}