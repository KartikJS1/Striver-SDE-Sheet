#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
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


************************************************************/

void solve1(BinaryTreeNode<int> *root, vector<int> &v)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    v.push_back(root->data);
    solve1(root->left, v);
    solve1(root->right, v);
}

void solve2(BinaryTreeNode<int> *root, vector<int> &v)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    solve2(root->left, v);
    v.push_back(root->data);
    solve2(root->right, v);
}

void solve3(BinaryTreeNode<int> *root, vector<int> &v)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    solve3(root->left, v);
    solve3(root->right, v);
    v.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<int> pre;
    vector<int> ino;
    vector<int> pos;
    solve1(root, pre);
    solve2(root, ino);
    solve3(root, pos);
    vector<vector<int>> ans;
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
}