#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2)
        return true;
    else
        return false;
}