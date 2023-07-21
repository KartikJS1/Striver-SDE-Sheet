#include <bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &v, int n)
{

    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
            {
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}