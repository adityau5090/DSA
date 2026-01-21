#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data, Node* left=nullptr, Node* right=nullptr){
        this->data = data;
        this->left = left;
        this->right = right; 
    }
};

class BinarySearchTree{
    public: 
    Node* root = nullptr;

    BinarySearchTree(){
        root = nullptr;
    }

    Node* insert(Node* root,int val){

        if(root == nullptr){
            return new Node(val);
        }
        // Insert in left subtree
        if(val <= root->data){
                root->left = insert(root->left,val);
            }
            //Insert in right subtree
            else{
                root->right  = insert(root->right,val);
            }

            return root;
        }
    

    void inOrder(Node* root){
        if(root == nullptr){
            return;
        }
        inOrder(root->left);
        cout<<root->data<<" ";  
        inOrder(root->right);
    }
};

int main(){
    BinarySearchTree bst;
    bst.root = bst.insert(bst.root,20);
    bst.root = bst.insert(bst.root,15);
    bst.root = bst.insert(bst.root,25);
    bst.root = bst.insert(bst.root,10);
    bst.root = bst.insert(bst.root,18);
    bst.root = bst.insert(bst.root,23);
    bst.root = bst.insert(bst.root,30);

    cout<<"Inorder Traversal : ";
    bst.inOrder(bst.root);
}

/*
  In Binary Search Tree ->
    . inOrder Traversal
    . Print Binary Search Treen in ascending order
    . Check whether bst is correct or not
  all are same because inOrder travesal print bst in 
  ascending order and if it not print in ascending order 
  that means our bst is not correct   
  */
