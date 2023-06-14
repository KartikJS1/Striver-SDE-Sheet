#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
        long int left = 0; long int right = n-1;
        long int ans = 0;
        long int maxleft = 0; long int maxright = 0;

        while(left <= right){
            if(arr[left] <= arr[right])
            {
                if(arr[left]>=maxleft) maxleft = arr[left];
                else ans+=(maxleft - arr[left]);

                left++;
            }
            else{
                if(arr[right]>=maxright) maxright = arr[right];
                else ans+=(maxright-arr[right]);

                right--;
            }
        }
        return ans;
}