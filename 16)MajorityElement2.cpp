#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
    }
    for (auto it : m)
    {
        if (it.second > (arr.size() / 3))
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}