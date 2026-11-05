// Longest Univalues Path

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

int dfs(Node* root, int &ans){
    if(root == nullptr) return 0;

    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);

    if(root->left && root->left->val == root->val){
        l++;
    } else l=0;

    if(root->right && root->right->val == root->val){
        r++;
    } else r=0;

    ans = max(ans, l+r);

    return max(l, r);
}

int longestUnivaluePath(Node* root){
    int ans = 0;
    dfs(root,ans);
    return ans;
}
int main() {

    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(5);

    cout<<"Longest path : "<<longestUnivaluePath(root);

    return 0;
}