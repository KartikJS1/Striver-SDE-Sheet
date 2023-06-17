int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // searching
        if ((arr[mid] != arr[mid + 1]) && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }
        // left half elimination
        if ((mid % 2 != 0 && arr[mid - 1] == arr[mid]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        { /*if index is odd and element on mid is equal to prev or
          if index is even ans element on mid is equal to next element then
          we are on left half and the single element is on right half*/
            low = mid + 1;
        }
        else
        { // right half elimination
            high = mid - 1;
        }
    }
    return -1;
}