#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> v;
    inorder(root, v);
    int n = v.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int sum = v[i] + v[j];
        if (sum == k)
            return true;
        else if (sum > k)
            j--;
        else
            i++;
    }
    return false;
}