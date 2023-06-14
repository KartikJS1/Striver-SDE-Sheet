#include <bits/stdc++.h>

void solve(int index, int sum, vector<int> &num, vector<int> &ans)
{
    // base case
    if (index == num.size())
    {
        ans.push_back(sum);
        return;
    }

    // pick up an element at index
    solve(index + 1, sum + num[index], num, ans);

    // dont pick element
    solve(index + 1, sum, num, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solve(0, 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}