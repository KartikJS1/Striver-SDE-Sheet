#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root)
{
    // We have to make one to one mapping of Node->data and horizontal distance
    vector<int> ans;
    // base case
    if (root == NULL)
        return ans;
    map<int, int> topNode;               // mapping of data and HorDist
    queue<pair<TreeNode<int> *, int>> q; // pair of node and HorDist
    q.push(make_pair(root, 0));          // pushing root and hordist at first is zero

    // Level Order Traversal
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> temp = q.front(); // taking out the front's data
        q.pop();                                     // takeout the value
        TreeNode<int> *frontNode = temp.first;       // this is front node
        int hd = temp.second;                        // this is hordist

        // making 1-1 mapping and if one value for hordist is not there in map
        if (topNode.find(hd) == topNode.end()) // if not present
        {
            topNode[hd] = frontNode->val; // make entry in map
        }

        if (frontNode->left) // if left is present
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right) // if right is present
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // storing the values in ans
    for (auto it : topNode)
    {
        ans.push_back(it.second);
    }

    return ans;
}