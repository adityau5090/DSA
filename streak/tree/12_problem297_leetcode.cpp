// Serialize and Deserialize Binary Tree 

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

void serialization(Node* root, string& s){
    if(root == nullptr){
        s.append("#,");
        return;
    }

    s += to_string(root->val) + ",";
    serialization(root->left, s);
    serialization(root->right, s);
}

string serialize(Node* root) {
    string s = "";
    serialization(root,s);
    return s;
}

// DESERIALIZATION
Node* deserialization(stringstream& ss) {

    string val;
    getline(ss, val, ',');

    if (val == "#") {
        return nullptr;
    }

    Node* root = new Node(stoi(val));

    root->left = deserialization(ss);
    root->right = deserialization(ss);

    return root;
}

Node* deserialize(string data) {
    stringstream ss(data);
    return deserialization(ss);
}

// INORDER TRAVERSAL
void inorder(Node* root) {

    if (root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    // Serialize
    string result = serialize(root);

    cout << "Serialized Tree: " << result << endl;


    return 0;
}