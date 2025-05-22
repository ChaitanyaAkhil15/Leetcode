// Problem Link : https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM
// This problem is a variation of the SubsetSumEqualToK problem. Here Since we are supposed to partition the array into two equal subsets, 
// we need to check if the sum of the array is even or not. If it is odd, we cannot partition it into two equal subsets. 
// If it is even, we can check if there exists a subset with sum equal to half of the total sum.
// Such that we know there exists another subset with the same sum.

// Recursive Approach
// TC : O(2^n)
// SC : O(n)
#include <bits/stdc++.h> 
bool solve(int ind, int k, vector<int>& arr) {
    if(k == 0)
        return true;

    if(ind == 0)
        return (arr[0] == k);
    
    bool pick = false;
    if(arr[ind] <= k) 
        pick = solve(ind - 1, k - arr[ind], arr);
    
    bool notPick = solve(ind - 1, k, arr);

    return pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    int sum = 0;
    int n = nums.size();
    for(auto& num : nums) {
        sum += num;
    }

    if(sum & 1)
        return false;

    return solve(n - 1, k, arr);
}

// -------------------------------------------------------------------------------------------------------------------->

// Memoization Approach
// TC : O(n * k)
// SC : O(n * k) + O(n)
#include <bits/stdc++.h> 
class Solution {
public:
    bool solve(int ind, int k, vector<vector<int>>& dp, vector<int>& arr) {
        if(k == 0)
            return true;

        if(ind == 0)
            return (arr[0] == k);
        
        if(dp[ind][k] != -1)
            return dp[ind][k];
            
        bool pick = false;
        if(arr[ind] <= k) 
            pick = solve(ind - 1, k - arr[ind], dp, arr);
        
        bool notPick = solve(ind - 1, k, dp, arr);

        return dp[ind][k] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto& num : nums) {
            sum += num;
        }

        if(sum & 1)
            return false;
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return solve(n - 1, sum / 2, dp, nums);
    }
};

// -------------------------------------------------------------------------------------------------------------------->
// Tabular Approach
// TC : O(n * k)
// SC : O(n * k)
bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(auto& num : nums) {
        sum += num;
    }

    if(sum & 1)
        return false;
    
    vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));

    for(int ind = 0; ind < n; ind++) {
        dp[ind][0] = true;
    }

    if(nums[0] <= sum/2)
        dp[0][nums[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= sum/2; target++) {
            bool pick = false;

            if(nums[ind] <= target)
                pick = dp[ind - 1][target - nums[ind]];
            
            bool notPick = dp[ind - 1][target];

            dp[ind][target] = pick || notPick;
        }
    }

    return dp[n - 1][sum / 2];
}

// -------------------------------------------------------------------------------------------------------------------->

// Tabular Approach Space Optimized
// TC : O(n * k)
// SC : O(k)

bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(auto& num : nums) {
        sum += num;
    }

    if(sum & 1)
        return false;
    
    vector<bool> prev(sum / 2 + 1, false);

    prev[0] = true;

    if(nums[0] <= sum/2)
        prev[nums[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        vector<bool> curr(sum / 2 + 1, false);
        for(int target = 1; target <= sum/2; target++) {
            bool pick = false;

            if(nums[ind] <= target)
                pick = prev[target - nums[ind]];
            
            bool notPick = prev[target];

            curr[target] = pick || notPick;
        }
        prev = curr;
    }

    return prev[sum / 2];
}
