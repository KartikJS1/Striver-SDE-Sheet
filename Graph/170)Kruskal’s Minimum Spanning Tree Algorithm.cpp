#include <bits/stdc++.h>

void update(vector<int> &rank, vector<int> &parent, int n)
{
    for (int i = 1; i <= n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{

    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph)
{

    // SORT BY LAMBDA FUNC

    sort(graph.begin(), graph.end(), [&](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    // USING 1 INDEXING

    vector<int> rank(n + 1);
    vector<int> parent(n + 1);

    update(rank, parent, n);
    int ans = 0;

    for (int i = 0; i < graph.size(); i++)
    {
        int u = findParent(graph[i][0], parent);
        int v = findParent(graph[i][1], parent);
        int w = graph[i][2];

        if (u != v)
        {
            ans += w;
            unionSet(u, v, parent, rank);
        }
    }
    return ans;
}