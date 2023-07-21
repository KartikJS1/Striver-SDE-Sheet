#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

class info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(TreeNode<int> *root, int &yes)
{
    // base case
    if (root == NULL)
        return {INT_MAX, INT_MIN, true, 0};

    info left = solve(root->left, yes);
    info right = solve(root->right, yes);

    info curr;
    curr.mini = min(left.mini, root->data);
    curr.maxi = max(right.maxi, root->data);
    curr.size = left.size + right.size + 1;

    if (left.isBST && right.isBST &&
        (root->data > left.maxi && root->data < right.mini))
    {
        curr.isBST = true;
    }
    else
        curr.isBST = false;

    if (curr.isBST == true)
    {
        yes = max(yes, curr.size);
    }

    return curr;
}

int largestBST(TreeNode<int> *root)
{
    int max_size = 0;
    info temp = solve(root, max_size);
    return max_size;
}