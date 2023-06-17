#include <bits/stdc++.h>

void solve(vector<int> &v, int index, vector<int> &temp,
           vector<vector<int>> &ans)
{
    if (index == v.size())
    {
        ans.push_back(temp);
        return;
    }

    // take
    temp.push_back(v[index]);
    solve(v, index + 1, temp, ans);
    // not take
    temp.pop_back();
    solve(v, index + 1, temp, ans);
}

vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> ans;
    int index = 0;
    vector<int> temp;
    solve(v, index, temp, ans);
    return ans;
}