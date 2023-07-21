#include <bits/stdc++.h>
int kthLargest(vector<int> &nums, int n, int k)
{
    // Approach: Using Min-Heap
    // Time Complexity: O(NlogK)
    // Space Complexity: O(K)
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            pq.push(nums[i]);
        }
        else
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    return pq.top();
}