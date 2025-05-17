// Problem Link : https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM

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
    return solve(n - 1, k, arr);
}

// -------------------------------------------------------------------------------------------------------------------->

// Memoization Approach
// TC : O(n * k)
// SC : O(n * k) + O(n)
#include <bits/stdc++.h> 
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

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return solve(n - 1, k, dp, arr);
}

// -------------------------------------------------------------------------------------------------------------------->
// Tabular Approach
// TC : O(n * k)
// SC : O(n * k)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for(int ind = 0; ind < n; ind++) {
        dp[ind][0] = true;
    }

    if(arr[0] <= k)
        dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool pick = false;

            if(arr[ind] <= target)
                pick = dp[ind - 1][target - arr[ind]];
            
            bool notPick = dp[ind - 1][target];

            dp[ind][target] = pick || notPick;
        }
    }

    return dp[n - 1][k];
}

// -------------------------------------------------------------------------------------------------------------------->

// Tabular Approach Space Optimized
// TC : O(n * k)
// SC : O(k)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false);

    prev[0] = true;

    if(arr[0] <= k)
        prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        vector<bool> curr(k + 1, false);

        for(int target = 1; target <= k; target++) {
            bool pick = false;

            if(arr[ind] <= target)
                pick = prev[target - arr[ind]];
            
            bool notPick = prev[target];

            curr[target] = pick || notPick;
        }

        prev = curr;
        prev[0] = true;
    }

    return prev[k];
}