#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    int cnt = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
            cnt++;
        else
            cnt--;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            count++;
        }
    }
    if (count > n / 2)
        return ele;
    else
        return -1;
}