// Binary Tree Tilt

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

int tilt(Node* root, int *total){
    if(root == nullptr) return 0;

    int L = tilt(root->left, total);
    int R = tilt(root->right, total);

    *total += abs(L - R);

    return (root->data + L + R);
}

int findTilt(Node* root){
    int total = 0;
    tilt(root, &total);
    return total;
}
int main() {

    Node* root = new Node(4);

    // Left subtree
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    // Right subtree
    root->right = new Node(9);
    root->right->right = new Node(7);

    cout<<"Tilt : "<<findTilt(root);

    return 0;
}