// Path Sum II

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

void helper(Node *root, int targetSum, vector<int> &temp, vector<vector<int>> &res){
    if(root == nullptr) return;

    targetSum -= root->val;
    temp.push_back(root->val);

    if(root->left == nullptr && root->right == nullptr){
        if(targetSum == 0){
            res.push_back(temp);
        }
    }else{
        helper(root->left, targetSum, temp, res);
        helper(root->right, targetSum, temp, res);
    }
    
    temp.pop_back();
}

vector<vector<int>> pathSum(Node* root, int targetSum){
    vector<vector<int>> res;
    vector<int>temp;
    if(root == nullptr) return res;

    helper(root, targetSum, temp,res);
    return res;
}

int main() {

    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->left = new Node(5);
    root->right->right->right = new Node(1);

    vector<vector<int>> result = pathSum(root, 22);
    for(int i=0; i<result.size(); i++){
        cout<<"{ ";
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"}";
    }

    return 0;
}