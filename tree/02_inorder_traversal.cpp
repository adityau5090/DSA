/* Inorder Traversal -> 
    1. First Left subtree
    2. Root Node
    3. Then Right subtree

   Postorder Traversal ->
    1. First Left subtree
    2. Right subtree
    3. Root Node 
*/

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data,Node* left=nullptr, Node* right =nullptr){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Tree{
    public:
    Node* root=nullptr;

    Tree(){
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
    }

    void inorder(Node* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void postorder(Node* root){
        if(root == nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};

int main(){
    Tree t;
    t.inorder(t.root);
    cout<<"\n";
    t.postorder(t.root);
}