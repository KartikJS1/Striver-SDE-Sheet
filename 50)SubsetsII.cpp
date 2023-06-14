#include <bits/stdc++.h>

void solve(int index, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
{
    ans.push_back(temp); // empty

    for (int i = index; i < arr.size(); i++)
    {
        // to avoid duplicates
        if (i != index && arr[i] == arr[i - 1])
            continue;

        // take
        temp.push_back(arr[i]);
        solve(i + 1, arr, temp, ans);

        // not take
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    solve(0, arr, temp, ans);

    return ans;
}