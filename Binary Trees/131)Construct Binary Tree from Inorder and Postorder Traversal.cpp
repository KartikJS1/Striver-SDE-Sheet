#include <bits/stdc++.h>

int position(vector<int> &inOrder, int size, int ele)
{

    for (int i = 0; i < size; i++)
    {

        if (inOrder[i] == ele)
        {

            return i;
        }
    }

    return -1;
}

TreeNode<int> *solve(vector<int> &postOrder, vector<int> &inOrder, int size, int &preIndex, int start, int end)
{

    if (preIndex > inOrder.size() || start > end)
    {

        return NULL;
    }

    int ele = postOrder[preIndex--];

    int index = position(inOrder, size, ele);

    TreeNode<int> *root = new TreeNode<int>(ele);

    root->right = solve(postOrder, inOrder, size, preIndex, index + 1, end);

    root->left = solve(postOrder, inOrder, size, preIndex, start, index - 1);

    return root;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)

{

    // Write your code here.

    int size = inOrder.size();

    int preIndex = size - 1;

    int start = 0;

    int end = size - 1;

    return solve(postOrder, inOrder, size, preIndex, start, end);
}