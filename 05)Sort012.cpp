#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
    // Method1
    // sort(arr,arr+n); //TC : O(nlogn)

    // Method2
    // 1)Keep three pointers low, mid, high
    // 2)When mid pointer is pointing to zero then swap(arr[low],arr[mid]) then low++ mid++
    // 3)When mid pointer is pointing to one then mid++
    // 4)When mid pounter is pointing to two then swap(arr[mid],arr[high]) then high--
    // This is a Dutch National Flag Algorithm
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high--]);
        }
    }
}
