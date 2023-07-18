#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int> *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;
    // New Level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}