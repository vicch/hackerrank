// Problem:
// Determine if a binary tree is a binary search tree.
// 
// Solution:
// If a tree is BST, either of its child tree must be BST, which means all
// nodes must be in a certain range. Check the tree recursively, and when going
// to left node, the upper bound is changed, and when going to right node, the
// lower bound is changed.

struct Node {
    int data;
    Node* left;
    Node* right;
}

bool check_bst(Node* root)
{
    if (!root)
        return false;

    // Assume all values are positive, and -1 is considered invalid
    return check_bst_sub(root, -1, -1);
}

bool check_bst_sub(Node* root, int min, int max)
{
    if (!root)
        return true;

    if (
        (min != -1 && root->data <= min) ||
        (max != -1 && root->data >= max) ||
        !check_bst_sub(root->left, min, root->data) ||
        !check_bst_sub(root->right, root->data, max)
    )
        return false;

    return true;
}