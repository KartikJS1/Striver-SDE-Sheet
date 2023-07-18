#include <bits/stdc++.h>
/*
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };
*/

bool solve(TreeNode<int> *root, vector<int> &ans, int x)
{
    if (root == NULL)
        return false;
    // push the root data in ans
    ans.push_back(root->data);
    // check if root data is equal to x
    if (root->data == x)
        return true;
    // make call for left and right subtrees
    bool left = solve(root->left, ans, x);

    bool right = solve(root->right, ans, x);

    if (left || right) // if anyone of them is true
    {
        return true;
    }
    ans.pop_back(); // else remove the element from ans
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    solve(root, ans, x);
    return ans;
}
