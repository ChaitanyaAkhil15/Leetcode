// Problem Link : https://leetcode.com/problems/coin-change/description/

// Memoization Approach
// TC : O(n * amount)
// SC : O(n * amount) + O(n)
class Solution {
public:
    int solve(int ind, vector<int>& coins, vector<vector<int>>& dp, int amount) {
        if(ind == 0) {
            if(amount == 0)
                return 0;
            if(amount >= coins[0] && amount % coins[0] == 0)
                return amount / coins[0];
            return 1e6;
        }

        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        int pick = INT_MAX;
        if(amount >= coins[ind])
            pick = 1 + solve(ind, coins, dp, amount - coins[ind]);
        
        int notPick = 0 + solve(ind - 1, coins, dp, amount);

        return dp[ind][amount] = min(pick, notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int ans = solve(n - 1, coins, dp, amount);
        if(ans == 1e6)
            return -1;
        return ans;
    }
};

// Tabulation Approach
// TC : O(n * amount)
// SC : O(n * amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        dp[0][0] = 0;
        for(int value = 1; value <= amount; value++) {
            if(value >= coins[0] && value % coins[0] == 0)
                dp[0][value] = value / coins[0];
            else
                dp[0][value] = 1e6;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int value = 0; value <= amount; value++) {
                int pick = INT_MAX;
                if(value >= coins[ind])
                    pick = 1 + dp[ind][value - coins[ind]];
                int notPick = 0 + dp[ind - 1][value];

                dp[ind][value] = min(pick, notPick);
            }
        }

        return (dp[n - 1][amount] == 1e6) ? -1 : dp[n - 1][amount];
        
    }
};

// Space Optimized Approach
// TC : O(n * amount)
// SC : O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount + 1, -1), curr(amount + 1, -1);

        prev[0] = 0;
        for(int value = 1; value <= amount; value++) {
            if(value >= coins[0] && value % coins[0] == 0)
                prev[value] = value / coins[0];
            else
                prev[value] = 1e6;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int value = 0; value <= amount; value++) {
                int pick = INT_MAX;
                if(value >= coins[ind])
                    pick = 1 + curr[value - coins[ind]];
                int notPick = 0 + prev[value];

                curr[value] = min(pick, notPick);
            }

            prev = curr;
        }

        return (prev[amount] == 1e6) ? -1 : prev[amount];
        
    }
};