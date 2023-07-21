#include <bits/stdc++.h>
void dfs(int src, map<int, vector<int>> &adjList, map<int, bool> &visited, stack<int> &st)
{

    visited[src] = true;

    for (auto &neighbour : adjList[src])
    {

        if (!visited[neighbour])
        {

            dfs(neighbour, adjList, visited, st);
        }
    }

    st.push(src);
}

void newdfs(int node, stack<int> &st, map<int, bool> &vis, map<int, vector<int>> &adjList

            ,
            vector<int> &check)
{

    vis[node] = true;

    check.push_back(node);

    for (auto &it : adjList[node])
    {

        if (!vis[it])
        {

            newdfs(it, st, vis, adjList, check);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)

{

    // adjacency list

    map<int, vector<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {

        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    for (int i = 0; i < n; i++)

        sort(adjList[i].begin(), adjList[i].end());

    //   step-1 topological ordering

    map<int, bool> visited;

    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {

            dfs(i, adjList, visited, st);
        }
    }

    // step-2 graph transpose : u-->v -------->   v-->u

    map<int, vector<int>> newadjList;

    for (auto it : adjList)
    {

        int u = it.first;

        for (auto v : it.second)
        {

            newadjList[v].push_back(u);
        }
    }

    // step-3  with using stack we perform dfs traversal

    vector<vector<int>> count;

    map<int, bool> vis;

    while (!st.empty())
    {

        int node = st.top();

        st.pop();

        if (!vis[node])
        {

            vector<int> check;

            newdfs(node, st, vis, newadjList, check);

            count.push_back(check);
        }
    }

    return count;
}