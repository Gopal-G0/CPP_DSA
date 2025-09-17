#include<iostream>
#include<queue>

// Tree Node Structure

struct TreeNode
{

    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int val)
    {

        left = right = NULL;
        data = val;
    }
};

void insert(TreeNode *root, int val)
{
    std :: queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        // If left child is empty → insert here
        if (temp->left == NULL)
        {
            temp->left = new TreeNode(val);
            return;
        }
        else
        {
            q.push(temp->left);
        }

        // If right child is empty → insert here
        if (temp->right == NULL)
        {
            temp->right = new TreeNode(val);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    std :: queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                std :: cout << node->data << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                std :: cout << "- "; // placeholder for null
            }
        }
        std::cout << std::endl;
    }
}


// Inorder Traversal to check structure
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int findDepth(TreeNode* root, int target, int depth = 0) {

    if(root == nullptr) return -1;   // Base Case: Tree is empty or target not found

    if(root -> data == target) return depth;  // if current Node matches target then -> return the depth

    // look for left subtree
    int leftDepth = findDepth(root -> left, target, depth + 1);
    if(leftDepth != -1) return leftDepth;   // if found in left subtree

    return findDepth(root -> right, target, depth + 1);
}

int main() {

    TreeNode* root = new TreeNode(1);
    insert(root,2);
    insert(root,4);
    insert(root,6);
    insert(root,1);
    insert(root,8);

    inorder(root);
    std::cout << std::endl;

    std::cout << findDepth(root,4) << std::endl;
    std::cout << std::endl;
    printLevelOrder(root);
    std::cout << std::endl;
    return 0;
}