/* Logic ->      Left Boundary excluding leaf node
                 Leaf Node
                 Right Boundary in reverse
*/

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

bool isLeaf(Node* node){
    if(node->left == nullptr && node->right == nullptr) return true;
    return false;
}

void addLeftBoudary(Node* root, vector<int> &res){
    Node* curr = root->left;
    while (curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(Node* root, vector<int> &res){
    Node* curr = root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(auto it = temp.rbegin(); it != temp.rend(); it++){
        res.push_back(*it);
    }
}

void addLeaves(Node* root, vector<int> & res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

vector<int> printBoundaries(Node* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoudary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}


int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> res = printBoundaries(root);

    cout << "Boundary Traversal: ";

    for (int val : res) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
