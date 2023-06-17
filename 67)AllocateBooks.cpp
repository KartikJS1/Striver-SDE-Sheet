#include <bits/stdc++.h>

bool isPossible(int n, int m, vector<int> &arr, long long int mid)
{
    int dayCount = 1;
    long long int timeCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (timeCount + arr[i] <= mid)
        {
            timeCount += arr[i];
        }
        else
        {
            dayCount++;
            if (dayCount > n || arr[i] > mid)
            {
                return false;
            }
            timeCount = arr[i];
            // timeCount = 0;
            // timeCount+=arr[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long int s = 0;
    long long int e;
    long long int sum = 0;
    for (int i = 0; i < time.size(); i++)
        sum += time[i];
    e = sum;

    long long int ans = -1;

    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        if (isPossible(n, m, time, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}