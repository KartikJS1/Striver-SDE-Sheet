#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        auto top = *(st.begin());
        int curr = top.second;
        int currDist = top.first;
        st.erase(top);
        for (auto i : adj[curr])
        {
            if (dist[i.first] > currDist + i.second)
            {
                auto record = st.find(make_pair(dist[i.first], i.first));
                if (record != st.end())
                {
                    st.erase(record);
                }
                dist[i.first] = currDist + i.second;
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    return dist;
}