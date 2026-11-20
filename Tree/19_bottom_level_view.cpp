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

vector<int> bottomLevelView(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;

    map<int,int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto top = q.front();
        q.pop();
        Node* node = top.first;
        int col = top.second;

        mpp[col] = node->data;

        if(node->left) q.push({node->left, col - 1});
        if(node->right) q.push({node->right, col + 1});
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);

    /*
              1
             / \
            2   3
           / \ / \
          4  5,6  7   // Here 5,6 come at bottom level with same col so we consider right one so 6 -> [1,8,6,9,7]
              / \
             8   9
    */

    vector<int> ans = bottomLevelView(root);

    for (auto val : ans) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}