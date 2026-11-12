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

vector<vector<int>> zigzag(Node* root){
    vector<vector<int>> res;
    if(root == nullptr) return res;

    queue<Node*> q;
    q.push(root);
    bool flag = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for(int i=0; i<size; i++){
            Node* node = q.front();
            q.pop();

            int index = (flag) ? i : (size - i - 1);

            level[index] = node->data;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        flag = !flag;
        res.push_back(level);
    }
    
    return res;
}
int main() {

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<vector<int>> res = zigzag(root);

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}