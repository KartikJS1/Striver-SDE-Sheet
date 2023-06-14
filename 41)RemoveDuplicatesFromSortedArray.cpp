#include <bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n)
{
    // map<int,int> m;
    // for(auto it : arr)
    // {
    // 	if(m.find(it) != m.end())
    // 	{
    // 		continue;
    // 	}
    // 	else{
    // 		m[it]++;
    // 	}
    // }
    // return m.size();

    if (arr.size() == 0)
        return 0;
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}