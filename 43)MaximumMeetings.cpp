#include <bits/stdc++.h>

vector<int> maximumMeetings(vector<int> &start, vector<int> &finish)
{

    vector<pair<int, pair<int, int>>> ans;

    for (int i = 0; i < start.size(); i++)
    {

        ans.push_back({finish[i], {i + 1, start[i]}});
    }

    sort(ans.begin(), ans.end());

    int n = ans.size();

    int e = -1;

    vector<int> res;

    for (auto val : ans)
    {

        if (val.second.second > e - 1)
        {

            res.push_back(val.second.first);

            e = val.first + 1;
        }
    }

    return res;
}