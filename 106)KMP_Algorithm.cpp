#include <bits/stdc++.h>
bool findPattern(string p, string s)
{
    bool ans = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (p == s.substr(i, p.length()))
        {
            ans = true;
        }
    }

    return ans;
}