#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // row
    int m = matrix[0].size(); // column
    vector<int> x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    // row -> 0
    for (int i = 0; i < x.size(); i++)
    {
        int index = x[i];
        for (int j = 0; j < m; j++)
        {
            matrix[index][j] = 0;
        }
    }

    // column -> 0
    for (int i = 0; i < y.size(); i++)
    {
        int index = y[i];
        for (int j = 0; j < n; j++)
        {
            matrix[j][index] = 0;
        }
    }
}