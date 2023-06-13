#include <bits/stdc++.h>
int solve(int row, int col, int m, int n, vector<vector<int>> &dp)
{
    if (row == (m - 1) && col == (n - 1))
        return 1;
    if (row >= m || col >= n)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];
    else
        return dp[row][col] =
                   solve(row + 1, col, m, n, dp) + solve(row, col + 1, m, n, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(0, 0, m, n, dp);
}