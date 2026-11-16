// Maximum Level Sum Of Binary Tree

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

int maxLevelSum(Node* root){
    if(root == nullptr) return 0;

    int level=0;
    int maxSum = INT_MIN;
    int ans = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        level++;
        int sum = 0;
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();
            
            sum += front->val;

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        if(sum > maxSum){
            maxSum = sum;
            ans = level;
        }

    }
    return ans;
}
int main() {

    Node* root = new Node(1);

    root->left = new Node(7);
    root->right = new Node(0);

    root->left->left = new Node(7);
    root->left->right = new Node(-8);

    root->right->left = new Node(9);

    cout << "Maximum Level: " << maxLevelSum(root) << endl;

    return 0;
}