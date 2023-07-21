#include <bits/stdc++.h>
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // base case
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (root->data > x)
    {
        // move to left part
        return searchInBST(root->left, x);
    }
    else
    {
        // move to right part
        return searchInBST(root->right, x);
    }
}