#include <bits/stdc++.h>

TreeNode<int> *constructTree(vector<int> &arr, int low, int high)
{
    if (low > high)
        return NULL;

    int mid = (low + high) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);

    root->left = constructTree(arr, low, mid - 1);
    root->right = constructTree(arr, mid + 1, high);

    return root;
}

TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return constructTree(arr, 0, n - 1);
}