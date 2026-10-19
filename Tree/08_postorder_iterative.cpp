// Post-order traversal without using recursion

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

void postorderIterative(Node* root){
    stack<Node*> st;
    Node *curr = root;

    while (curr != NULL || !st.empty()){
        
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }else{
                curr = temp;
            }
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
    postorderIterative(root);

    return 0;
}