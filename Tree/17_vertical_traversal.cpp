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

vector<vector<int>> verticalTraversal(Node* root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();

        Node* node = p.first;
        int x = p.second.first; int y = p.second.second;
        nodes[x][y].insert(node->data);
        
        if(node->left) todo.push({node->left, {x-1, y+1}});
        if(node->right) todo.push({node->right, {x+1, y+1}});
    }
    vector<vector<int>> ans;
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
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

    vector<vector<int>> ans = verticalTraversal(root);

    for (auto col : ans) {
        for (auto val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}