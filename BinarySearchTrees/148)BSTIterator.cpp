#include <bits/stdc++.h>

class BSTiterator
{
private:
    stack<TreeNode<int> *> st;

public:
    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int> *node = st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
    void pushAll(TreeNode<int> *root)
    {
        for (; root != NULL; st.push(root), root = root->left)
            ;
    }
};