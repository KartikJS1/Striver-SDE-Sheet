int search(int *arr, int n, int key)
{
    // Identify the sorted half
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;

        // if left sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= key && key <= arr[mid])
            // means key is lying within it and key is also lesser than mid
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right sorted
        else
        {
            if (arr[mid] <= key && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}