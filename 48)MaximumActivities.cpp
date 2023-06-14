
#include <bits/stdc++.h>
static bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int maximumActivities(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({start[i], end[i]});
    sort(v.begin(), v.end(), comp);
    int count = 1;
    int last = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first < last)
            continue;
        else
        {
            count++;
            last = v[i].second;
        }
    }
    return count;
}
