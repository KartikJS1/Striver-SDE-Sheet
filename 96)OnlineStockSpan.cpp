#include <bits/stdc++.h>

class StockPlanner
{
private:
    stack<pair<int, int>> s;

public:
    int next(int price)
    {
        int day = 1;
        while (!s.empty() and price >= s.top().first)
        {
            day += s.top().second;
            s.pop();
        }

        s.push({price, day});
        return day;
    }
};

vector<int> findSpans(vector<int> &price)
{
    vector<int> ans;
    StockPlanner s;

    for (auto p : price)
    {
        int span = s.next(p);
        ans.push_back(span);
    }

    return ans;
}