// problem link : https://leetcode.com/problems/partition-array-for-maximum-sum

// Memoization Approach
// TC : O(n * k)
// SC : O(n) + O(n) stack space
class Solution {
public:
    int solve(int ind, vector<int>& arr, int k, vector<int>& dp) {
        if(ind >= arr.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];

        int ans = 0;
        int mx = 0;
        for(int i = ind; i < ind + k && i < arr.size(); i++) {
            mx = max(mx, arr[i]);
            ans = max(ans, mx * (i - ind + 1) + solve(i + 1, arr, k, dp));
        }

        return dp[ind] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};


// Tabulation Approach
// TC : O(n * k)
// SC : O(n)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for(int ind = n - 1; ind >= 0; ind--) {
            int ans = 0;
            int mx = 0;
            for(int i = ind; i < ind + k && i < arr.size(); i++) {
                mx = max(mx, arr[i]);
                ans = max(ans, mx * (i - ind + 1) + dp[i + 1]);
            }
            dp[ind] = ans;
        }

        return dp[0];
    }
};