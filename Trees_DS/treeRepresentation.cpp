#include<bits/stdc++.h>
using namespace std;

//Node Representation of Tree
struct TreeNode {

    int value;
    TreeNode* left;
    TreeNode* right;

    //constructor
    TreeNode(int val) {

        value = val;
        left = right = NULL;
    }
};

//Preorder Traversal - Root, left, right
void preorderRec(TreeNode* node, vector<int>& out) {

    if(!node) return;

    out.push_back(node -> value);
    preorderRec(node -> left, out);
    preorderRec(node -> right,out);
}

//Inorder - Left, root, right
void inorderRec(TreeNode* node, vector<int>& out) {

    if(!node) return;

    inorderRec(node -> left,out); // visit left subtree

    out.push_back(node -> value); // visit root node

    inorderRec(node -> right,out); //visit right subtree
}

// Postorder - Left, Right, Root
void PostorderRec(TreeNode* node, vector<int>& out) {

    if(!node) return;

    PostorderRec(node -> left, out);
    PostorderRec(node -> right, out);

    out.push_back(node -> value);
}

int main() {

    TreeNode* root = new TreeNode(1); // creates root node

    root -> left = new TreeNode(2);  // creates left node
    root -> right = new TreeNode(3);// creates right node

    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);

    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    vector<int> out;
    preorderRec(root,out);

    cout << "Preorder Traversal: ";
    for(int nodeValues: out) {
        cout << nodeValues << " ";
    }

    cout << endl;
    
    vector<int> out1;
    inorderRec(root, out1);

    cout << "Inorder Traversal: ";
    for(int nodeValues: out1) {
        cout << nodeValues << " ";
    }

    cout << endl;

    vector<int> out2;
    PostorderRec(root, out2);

    cout << "Postorder Traversal: ";
    for(int nodeValues: out2) {
        cout << nodeValues << " ";
    }

    cout << endl;

    return 0;
}