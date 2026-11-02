// Path Sum

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

bool hasPathSum(Node* root, int targetSum){
    if(root == NULL) return false;

    if(root->left == NULL && root->right == NULL){
        return targetSum == root->data;
    }

    targetSum -= root->data;

    return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
}
int main() {

    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    cout<<hasPathSum(root, 21);

    return 0;
}