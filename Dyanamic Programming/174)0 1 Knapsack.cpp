#include <bits/stdc++.h>
int solve(int ind, vector<int> &val, vector<int> &wt, int w, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= w)
            return val[0];
        else
            return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int notTake = 0 + solve(ind - 1, val, wt, w, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
        take = val[ind] + solve(ind - 1, val, wt, w - wt[ind], dp);
    return dp[ind][w] = max(take, notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, values, weights, w, dp);
}