
// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays
// This is an extension to finding subarray with maximum sum using kadane's algorithm (here we have to return the subarray too)

#include <bits/stdc++.h>
class Solution {
  public:
    long long pairWithMaxSum(long long arr[], long long N) {
        long long sum = 0;
        
        long long max = arr[0];
        long long min = arr[0];
        
        for(int i = 1; i < N; i++)
        {
            if(arr[i] + arr[i-1] > sum)
                sum = arr[i] + arr[i-1];
            // sum = max(sum, max + min);
        }
        
        return sum;
        
    }
};