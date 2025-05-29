// Problem Link : https://leetcode.com/problems/coin-change-ii/

// Memoization Approach
// TC : O(n * amount)
// SC : O(n * amount) + O(n)
class Solution {
public:
    int solve(int ind, vector<int>& coins, vector<vector<int>>& dp, int amount) {
        if(ind == 0) {
            if(amount % coins[0] == 0)
                return 1;
            return 0;
        }

        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        
        int pick = 0;
        if(coins[ind] <= amount)
            pick = solve(ind, coins, dp, amount - coins[ind]);

        int notPick = solve(ind - 1, coins, dp, amount);

        return dp[ind][amount] = pick + notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        return solve(n - 1, coins, dp, amount);
    }
};

// Tabulation Approach
// TC : O(n * amount)
// SC : O(n * amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long int>> dp(n, vector<long long int>(amount + 1, 0));

        
        dp[0][0] = 1;
        for(int value = coins[0]; value <= amount; value++) {
            if(value % coins[0] == 0)
                dp[0][value] = 1;
        }
        
        for(int ind = 1; ind < n; ind++) {
            for(int value = 0; value <= amount; value++) {
                
                int pick = 0;
                if(coins[ind] <= value)
                    pick = dp[ind][value - coins[ind]];

                int notPick = dp[ind - 1][value];

                dp[ind][value] = (long long int)pick + notPick;
            }
        }

        return dp[n - 1][amount];
    }
};

// Most Optimal Approach
// TC : O(n * amount)
// SC : O(amount)
// If we carefully observe the tabulation approach, in notPick case we are considering dp[ind - 1][value] and for pick case
// we are considering dp[ind][value - coins[ind]]. This means that we are not using the previous row for pick case.
// Until value < coins[ind], the values of curr array will be the same as the previous row.
// So we can rather use the previous row itself to compute the current row's values.
// That's why 1D works here.

// And Until value < coins[ind] the values of current row will remain unchanged.
// So we can start the iterarion from coins[ind] in inner loop.
int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<uint64_t> dp(amount + 1, 0);

        dp[0] = 1;
        for(int value = coins[0]; value <= amount; value++) {
            if(value % coins[0] == 0)
                dp[value] = 1;
        }
        
        for(int ind = 1; ind < n; ind++) {
            for(int value = coins[ind]; value <= amount; value++) {
                dp[value] = dp[value] + dp[value - coins[ind]];
            }
        }

        return dp[amount];
    }