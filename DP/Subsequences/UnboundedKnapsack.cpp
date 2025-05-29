// Problem Link : https://www.naukri.com/code360/problems/unbounded-knapsack_1215029

// Memoization Approach
// TC : O(n * w)
// SC : O(n * w) + O(w)
// The Stack Space here is o(w) because we can use the same weight multiple times
#include <bits/stdc++.h>
int solve(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp) {
    if(ind == 0) {
        return (w / weight[0]) * profit[0];
    }

    if(dp[ind][w] != -1)
        return dp[ind][w];

    int pick = INT_MIN;
    if(weight[ind] <= w)
        pick = profit[ind] + solve(ind, w - weight[ind], profit, weight, dp);
    
    int notPick = solve(ind - 1, w, profit, weight, dp);

    return dp[ind][w] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    return solve(n - 1, w, profit, weight, dp);
}

// Tabular Approach
//// TC : O(n * w)
// SC : O(n * w)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for(int wt = weight[0]; wt <= w; wt++) {
        dp[0][wt] = (wt / weight[0]) * profit[0];
    }

    for(int ind = 1; ind < n; ind++) {
        for(int wt = 0; wt <= w; wt++) {
            int pick = INT_MIN;
            if(weight[ind] <= wt)
                pick = profit[ind] + dp[ind][wt - weight[ind]];
            
            int notPick = dp[ind - 1][wt];

            dp[ind][wt] = max(pick, notPick);
        }
    }

    return dp[n - 1][w];
}

// Space Optimized 1D approach
#include <bits/stdc++.h>
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> dp(w + 1, 0);

    for(int wt = weight[0]; wt <= w; wt++) {
        dp[wt] = (wt / weight[0]) * profit[0];
    }

    for(int ind = 1; ind < n; ind++) {
        for(int wt = weight[ind]; wt <= w; wt++) {
            dp[wt] = max(profit[ind] + dp[wt - weight[ind]], dp[wt]);
        }
    }

    return dp[w];
}