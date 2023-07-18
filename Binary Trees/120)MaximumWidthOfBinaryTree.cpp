#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    queue<TreeNode<int> *> level;
    level.push(root);

    int width = level.size();

    while (!level.empty())
    {

        int size = level.size();

        while (size--)
        {
            TreeNode<int> *front = level.front();
            level.pop();

            if (front->left)
            {
                level.push(front->left);
            }

            if (front->right)
            {
                level.push(front->right);
            }
        }
        int curr_size = level.size();
        width = max(width, curr_size);
    }
    return width;
}