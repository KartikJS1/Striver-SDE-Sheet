#include <bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<int, map<int, vector<int>>> m; // mapping of HorDist and another mapping
    // of level and list of nodes at that level
    queue<pair<TreeNode<int> *, pair<int, int>>> q; // pair of node and HorDist and level

    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0))); // pushing the root and curr hordist and level

    // Level Order Traversal
    while (!q.empty())
    {
        // take out the front value in queue
        pair<TreeNode<int> *, pair<int, int>> temp = q.front();
        q.pop();

        // take out the front node
        TreeNode<int> *frontNode = temp.first;
        // take out the horDist
        int hd = temp.second.first;
        // take out the level
        int level = temp.second.second;

        // Now on whichever node you are make a corresponding entry in map
        m[hd][level].push_back(frontNode->data); // insertin vector of nodes

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : m)
    {
        // i is row representing int and map i.e hd and level and vector of nodes
        //  we want vector of nodes
        for (auto j : i.second)
        {
            // j represent a row of level and vector
            // we want vector of nodes
            for (auto k : j.second)
            {
                // k represent a vector
                ans.push_back(k);
            }
        }
    }

    return ans;
}