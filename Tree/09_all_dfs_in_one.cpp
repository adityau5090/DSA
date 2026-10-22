// Pre-order, In-order and Post-order Traversal

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

vector<vector<int>> preInPostTraversal(Node* root){
    vector<int> pre, in, post;

    if(root == NULL) return {pre, in, post};

    stack<pair<Node*,int>> st;
    st.push({root, 1});

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        // pre-order
        // increment 1 to 2
        // push the left side of the tree

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }

        // in-order
        // increment 2 to 3
        // push right side of tree
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }

        // post-order
        else{
            post.push_back(it.first->data);
        }
    }

    return {pre, in, post};
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right= new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> res = preInPostTraversal(root);

    cout<<"Pre-order : ";
    for(int it: res[0]) cout<<it<<" ";
    cout<<endl;
    cout<<"In-order : ";
    for(int it: res[1]) cout<<it<<" ";
    cout<<endl;
    cout<<"Post-order : ";
    for(int it: res[2]) cout<<it<<" ";

    return 0;
}