#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &a, int n)
{

    // Method1
    // next_permutation(A.begin(),A.end());
    // return A;

    // Method2
    // Step1 -> Find out the break point where a[i] < a[i+1]
    // Step2 -> Find someone greater than a[i] but the smallest
    // Step3 -> Place all other remaining elements in sorted order

    int index = -1;
    // int n = a.size();
    for (int i = n - 2; i >= 0; i--) // since (n-2) is the greatest element where the dip can be there
    {
        if (a[i] < a[i + 1])
        {
            index = i; // Step1
            break;
        }
    }
    if (index == -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }

    for (int i = n - 1; i > index; i--)
    {
        if (a[i] > a[index]) // We got some one greater to swap
        {
            // Step2
            swap(a[i], a[index]);
            break;
        }
    }
    // Step3
    reverse(a.begin() + index + 1, a.end());

    return a;
}