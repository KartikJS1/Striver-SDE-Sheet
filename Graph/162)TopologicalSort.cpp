#include <bits/stdc++.h>
void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> adj[v];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }

    vector<int> vis(v + 1, 0);
    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}