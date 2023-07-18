#include <bits/stdc++.h>
/************************************************************

    Following is the Tree node structure

    template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long int func(TreeNode<int> *root, long long int &ans)
{

    if (root == NULL)
        return 0;

    // find left and right max sum of current node so that we can return to parent node

    long long int left = func(root->left, ans);

    long long int right = func(root->right, ans);

    ans = max(ans, root->val + left + right);

    return root->val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root)

{

    // if root is null or root has no leaves then return -1

    if (root == NULL || root->left == NULL || root->right == NULL)
        return -1;

    long long int ans = 0;

    func(root, ans);

    return ans;
}