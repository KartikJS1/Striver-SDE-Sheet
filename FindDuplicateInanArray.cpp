#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    map<int, int> m;
    int ans = 0;
    for (auto i : arr)
    {
        m[i]++;
        if (m[i] > 1)
            return i;
    }
    return -1;
}
