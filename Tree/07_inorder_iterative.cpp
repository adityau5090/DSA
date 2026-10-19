// In-order traversal without using recursion

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorderIterative(Node* root){
    stack<Node*> st;
    Node * node = root;
    while (true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    } 
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    cout<<"Pre-order Traversal : "<<"\n";
    inorderIterative(root);

    return 0;
}