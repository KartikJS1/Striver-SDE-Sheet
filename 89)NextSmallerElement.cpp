#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{

    stack<pair<int, int>> s;
    s.push({arr[0], 0});

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top().first > arr[i])
        {
            ans[s.top().second] = arr[i];
            s.pop();
        }
        s.push({arr[i], i});
    }

    while (!s.empty())
    {
        ans[s.top().second] = -1;
        s.pop();
    }
    return ans;
}