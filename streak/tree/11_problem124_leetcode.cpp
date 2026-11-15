// Maximum Path Sum

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

int maxPath(Node* root, int& sum){
        if(root == nullptr) return 0;

        int l = max(0, maxPath(root->left, sum));
        int r = max(0, maxPath(root->right, sum));

        sum = max(sum, (root->val + l + r));

        return root->val + max(l, r);
    }
    int maxPathSum(Node* root) {
        int sum = INT_MIN;
        maxPath(root, sum);
        return sum;
    }

int main() {

    Node* root = new Node(-10);

    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    return 0;
}