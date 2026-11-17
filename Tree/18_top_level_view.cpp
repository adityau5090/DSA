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

vector<int> topLevelView(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;

    map<int,int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int col = it.second;
        
        if(mpp.find(col) == mpp.end()) mpp[col] = node->data;  // push in map if it is not exist

        if(node->left) q.push({node->left, col - 1});
        if(node->right) q.push({node->right, col + 1});
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;      
}

int main() {

    /*
              1
             / \
            2   3
           / \
          4   5
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = topLevelView(root);

    for (auto val : ans) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}