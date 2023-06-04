#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);//remembering the past
    }
    return profit;
}
