void dfs(int node, vector<int> adj[], vector<int> &temp, vector<int> &vis)
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto i : adj[node])
        if (!vis[i])
            dfs(i, adj, temp, vis);
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    vector<int> adj[v], vis(v);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<vector<int>> res;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(i, adj, temp, vis);
            res.push_back(temp);
        }
    }

    return res;
}