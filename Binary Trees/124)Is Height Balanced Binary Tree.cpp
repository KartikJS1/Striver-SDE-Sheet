#include <bits/stdc++.h>

/*************************************************************



    Following is the Binary Tree node structure



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



*************************************************************/

// this is an O(n) soln

pair<bool, int> solve(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {

        return {1, 0};
    }

    pair<bool, int> leftAns = solve(root->left);

    pair<bool, int> rightAns = solve(root->right);

    pair<bool, int> ans;

    if (leftAns.first && rightAns.first)
    {

        if (abs(leftAns.second - rightAns.second) <= 1)
        {

            ans.first = 1;
        }

        else
        {

            ans.first = 0;
        }
    }

    ans.second = 1 + max(leftAns.second, rightAns.second);

    return ans;
}

bool isBalancedBT(BinaryTreeNode<int> *root) { return solve(root).first; }