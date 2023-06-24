#include <bits/stdc++.h>

string reverseString(string &s)
{

    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string word = "";

        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        if (!word.empty())
            st.push(word);
    }
    string ans = "";
    while (!st.empty())
    {
        ans = ans + st.top();
        ans.push_back(' ');
        st.pop();
    }

    return ans;
}