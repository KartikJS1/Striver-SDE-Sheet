#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int, int> m;
    for (auto it : arr)
    {
        m[it]++;
    }
    vector<pair<int, int>> p;
    vector<int> ans;
    for (auto it : m)
    {
        p.push_back({it.second, it.first});
    }
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < k; i++)
    {
        ans.push_back(p[i].second);
    }
    sort(ans.begin(), ans.end());
    return ans;
}