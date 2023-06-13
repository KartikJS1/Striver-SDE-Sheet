#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int missing = 0;
    int repeating = 0;
    int sum = 0;
    map<int, int> m;
    for (auto it : arr)
    {
        m[it]++;
        sum += it;
    }
    for (auto it : m)
    {
        if (it.second > 1)
        {
            repeating = it.first;
        }
    }
    missing = (n * (n + 1) / 2) + repeating - sum;
    return {missing, repeating};
}
