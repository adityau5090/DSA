// Maximum Depth Of Binary Tree

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

int maximumDepth(Node* root){
    if(root == NULL) return 0;

    int leftSubtreeDepth = maximumDepth(root->left);
    int rightSubtreeDepth = maximumDepth(root->right);

    return 1 + max(leftSubtreeDepth, rightSubtreeDepth);
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right= new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Max depth : "<<maximumDepth(root);

    return 0;
}