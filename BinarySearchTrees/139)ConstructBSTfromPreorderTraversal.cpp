#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int> *solve(vector<int> &preOrder, int &i, int bound, int n)
{
    if (i >= n || preOrder[i] > bound)
    {
        return NULL;
    }

    TreeNode<int> *root = new TreeNode<int>(preOrder[i++]);

    root->left = solve(preOrder, i, root->data, n);
    root->right = solve(preOrder, i, bound, n);

    return root;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    int i = 0;
    int n = preOrder.size();
    return solve(preOrder, i, INT_MAX, n);
}