// Same tree

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

bool isSameTree(Node* p, Node* q){
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;
    

    if(p->val != q->val) return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    isSameTree(root, root) == 1 ? cout<<"Same" : cout<<"Not same";
    return 0;
}