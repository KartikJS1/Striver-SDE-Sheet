#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int k = min(m, n);
    for (int i = 0; i < k / 2; i++)
    {
        int top = i, left = i, bottom = n - 1 - i, right = m - 1 - i;

        int x = mat[top][left];
        for (int j = left + 1; j <= right; j++)
        {
            swap(mat[top][j], x);
        }
        for (int j = top + 1; j <= bottom; j++)
        {
            swap(mat[j][right], x);
        }
        for (int j = right - 1; j >= left; j--)
        {
            swap(mat[bottom][j], x);
        }
        for (int j = bottom - 1; j >= top; j--)
        {
            swap(mat[j][left], x);
        }
    }
}
