#include <bits/stdc++.h>
int uniqueSubstrings(string s)
{
    vector<int> dict(256, -1);
    int maxi = 0;
    int start = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (dict[s[i]] > start)
        {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxi = max(maxi, i - start);
    }
    return maxi;
}