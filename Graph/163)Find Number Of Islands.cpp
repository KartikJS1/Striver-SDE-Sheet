#include <bits/stdc++.h>
using namespace std;

void bfs(int r, int c, int **grid, vector<vector<int>> &vis, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    vis[r][c] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nx = x + i, ny = y + j;

                if (nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] == 1 and !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int getTotalIslands(int **arr, int n, int m)
{
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] and arr[i][j] == 1)
            {
                bfs(i, j, arr, vis, n, m);
                count++;
            }
        }
    }
    return count;
}