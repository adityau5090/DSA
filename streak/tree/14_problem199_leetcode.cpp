// Binary Tree Right Side View

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = right = nullptr;
    }
};
vector<int> rightSideView(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i=0; i<size; i++){
            Node* front = q.front(); 
            q.pop();
            if(i==size-1) ans.push_back(front->val);

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
    return ans;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    vector<int> res = rightSideView(root);
    for(int it: res){
        cout<<it<<" ";
    }

    return 0;
}