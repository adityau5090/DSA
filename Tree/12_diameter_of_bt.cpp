// Diameter -> Length of longest path between any two nodes

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

int height(Node* root, int &diameter){
    if(root == NULL) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh+rh);

    return 1 + max(lh, rh);
}

int diameter(Node* root){
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    root->right->right->right = new Node(7);
    root->right->left->left->left = new Node(9);
    root->right->right->right->right = new Node(8);

    cout<<"Diameter : "<<diameter(root);
    return 0;
}