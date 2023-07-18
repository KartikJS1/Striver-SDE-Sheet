vector<int> stringMatch(string text, string pattern)
{
    vector<int> v;
    for (int i = 0; i < text.size(); i++)
    {
        if (pattern == text.substr(i, pattern.size()))
        {
            v.push_back(i + 1);
        }
    }
    // for(auto it : v) cout<<it<<" "; cout<<endl;
    return v;
}
