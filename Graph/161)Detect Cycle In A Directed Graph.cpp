bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse all adj nodes
    for (auto it : adj[node])
    {
        if (!vis[it])
        { // node not visited
            if (dfs(it, vis, pathVis, adj) == true)
                return true;
        }
        else if (pathVis[it])
        { // node prev visited but it has to be on same path
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    vector<int> adj[n + 1];

    for (auto it : edges)
    {
        adj[it.first].push_back(it.second);
    }

    vector<int> vis(n + 1, 0);

    vector<int> pathVis(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, pathVis, adj) == true)
                return true;
        }
    }
    return false;
}