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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> result;
    queue<BinaryTreeNode<int> *> q;

    bool lefttoright = true;

    if (root == NULL)
        return result;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> sub(n);
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *curr = q.front();
            q.pop();

            int index = lefttoright ? i : n - i - 1;
            sub[index] = curr->data;

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }

        lefttoright = !lefttoright;
        for (auto i : sub)
        {
            result.push_back(i);
        }
    }
    return result;
}
