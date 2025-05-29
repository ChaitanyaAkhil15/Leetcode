// Problem Link : https://leetcode.com/problems/target-sum/description/

// The Best Approach uses DP-18 Count Partitions With Given Difference
// This problem can be boiled down to partitioning all the elements with positive signs to one subset 
// and all the elements with negative signs to another subset.
// The difference between the two subsets should be equal to the target value.
// This is the most optimal in terms of time because we only have to find a partition with sum (totalSum - target) / 2.

// Memoization Approach
// TC : O(n * target)
// SC : O(n * target) + O(n)
class Solution {
public:
    int solve(int ind, vector<int>& nums, unordered_map<int, unordered_map<int, int>>& dp, int target) {
        
        if(ind < 0) {
            if(target == 0)
                return 1;
            return 0;
        }

        if(dp[ind].find(target) != dp[ind].end())
            return dp[ind][target];
        
        int add = solve(ind - 1, nums, dp, target - nums[ind]);
        int subtract = solve(ind - 1, nums, dp, target + nums[ind]);

        return dp[ind][target] = add + subtract;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>> dp;
        
        return solve(n - 1, nums, dp, target);
    }
};

// Best Approach
// TC : O(n * target)
// SC : O(target)
class Solution {
public:
    int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;

    for(auto &ele : arr)
        totSum += ele;
    
    if(totSum - d < 0 || (totSum - d) & 1)
        return 0;

    int sumToFind = (totSum - d) / 2;
    
    vector<int> prev(sumToFind + 1, 0);
    
    if(arr[0] == 0)
        prev[0] = 2; // Two ways to choose nothing (Pick or Not Pick)
    else
        prev[0] = 1; // One way to choose nothing (Not Pick)
    
    if(arr[0] <= sumToFind && arr[0] != 0) prev[arr[0]] = 1; // One way to choose the first element if it equals k

    for(int ind = 1; ind < n; ind++) {
        vector<int> curr(sumToFind + 1, 0);
        for(int sum = 0; sum <= sumToFind; sum++) {
            int pick = 0;
            if(arr[ind] <= sum)
                pick = prev[sum - arr[ind]];

            int notPick = prev[sum];

            curr[sum] = (pick + notPick);
        }
        prev = curr;
    }
    return prev[sumToFind];
}
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        return countPartitions(n, target, nums);
    }
};