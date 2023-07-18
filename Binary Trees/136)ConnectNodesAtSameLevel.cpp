#include <bits/stdc++.h>

void connectNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            auto p = q.front();
            q.pop();

            p->next = n ? q.front() : NULL;
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
}