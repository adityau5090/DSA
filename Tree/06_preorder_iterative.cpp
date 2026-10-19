// Pre-order traversal without using recursion

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

void preorderIterative(Node* root){
    stack<Node*> st;
    st.push(root);

    while (!st.empty()){
        Node* top = st.top();
        st.pop();
        cout<<top->data<<" ";
        if(top->right != NULL) st.push(top->right);
        if(top->left != NULL) st.push(top->left);
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
    preorderIterative(root);

    return 0;
}