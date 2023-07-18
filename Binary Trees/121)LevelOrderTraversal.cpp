#include <bits/stdc++.h>
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    // Level Order Traversal
    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        ans.push_back(temp->val);
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    return ans;
}