// Validate Binary Search Tree


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

int maxLeft(Node* root){
    if(root == nullptr) return INT_MIN;
    return max(root->data, max(maxLeft(root->left), maxLeft(root->right)));
}
int minRight(Node* root){
    if(root == nullptr) return INT_MAX;
    return min(root->data, min(minRight(root->left), minRight(root->right)));
}

bool isValidBST(Node* root){
    if(root == nullptr) return true;

    int maximumLeft = maxLeft(root->left);
    int minimumRight = minRight(root->right);

    if(maximumLeft >= root->data || minimumRight <= root->data) return false;

    return isValidBST(root->left) && isValidBST(root->right);
}


// Optimize Approach 
bool isValidBST2(Node* root, long long minVal, long long maxVal){
    if(root == nullptr) return true;

    if(root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    return (isValidBST2(root->left, minVal, root->data) && (isValidBST2(root->right, root->data, maxVal)));
}

int main() {

    Node* root = new Node(5);

    // Left subtree
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    // Right subtree
    root->right = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(9);


    cout<<"Is BST : "<<isValidBST2(root, LLONG_MIN, LLONG_MAX);
    return 0;
}