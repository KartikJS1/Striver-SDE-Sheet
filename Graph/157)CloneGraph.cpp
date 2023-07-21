#include <bits/stdc++.h>
/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
            data = 0;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
            data = val;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
            data = val;
            this->neighbours = neighbours;
        }
    };

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
    graphNode *copy_node;
    unordered_map<graphNode *, graphNode *> mp;
    if (node)
    {
        copy_node = new graphNode(node->data);
        mp[node] = copy_node;
    }
    queue<graphNode *> q;
    q.push(node);

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        for (auto nb : temp->neighbours)
        {
            if (mp.find(nb) == mp.end()) // not visisted
            {
                graphNode *c = new graphNode(nb->data);
                mp[nb] = c; // mark visited
                q.push(nb);
            }
            mp[temp]->neighbours.push_back(mp[nb]);
        }
    }

    return copy_node;
}