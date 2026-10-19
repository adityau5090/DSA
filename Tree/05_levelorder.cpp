// Level-order traversal  

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void levelorder(Node *root){
    if(root == NULL) return;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        cout<<"{ ";
        for(int it: level){
            cout<<it<<" ";
        }
        cout<<"}\n";
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);    
    root->right = new Node(3);    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Level-order traversal : "<<"\n";
    levelorder(root);

    return 0;
}