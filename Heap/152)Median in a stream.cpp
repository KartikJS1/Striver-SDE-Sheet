#include <bits/stdc++.h>

void balance(priority_queue<int> &maxh, priority_queue<int, vector<int>, greater<int>> &minh)
{
    if (maxh.size() > minh.size() + 1)
    {
        int z = maxh.top();
        minh.push(z);
        maxh.pop();
    }

    else if (minh.size() > maxh.size())
    {
        int z = minh.top();
        minh.pop();
        maxh.push(z);
    }
}
vector<int> findMedian(vector<int> &arr, int n)
{

    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> v;
    // maxh.push(arr[0]);

    for (int i = 0; i < n; i++)
    {
        if (maxh.size() == 0 || maxh.top() > arr[i])
            maxh.push(arr[i]);
        else
            minh.push(arr[i]);

        balance(maxh, minh);

        if (i % 2 == 0)
            v.push_back(maxh.top());
        else
            v.push_back((maxh.top() + minh.top()) / 2);
    }

    return v;
}