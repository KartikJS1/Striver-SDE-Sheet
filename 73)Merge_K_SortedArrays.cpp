#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> ans;
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j = 0; j<arr[i].size(); j++)
        {
            ans.push_back(arr[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
