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

bool isSameTree(Node* root1, Node* root2){
    if(root1 == nullptr || root2 == nullptr){
        return root1 == root2;
    }

    return (root1->data == root2->data) && (isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    isSameTree(root, root2) == 1 ? cout<<"True" : cout<<"False"; 
    return 0;
}