// problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

// This problem is a variant of Stocks2.cpp, in Stocks2 we are allowed to make unlimited transactions, while here we can make unlimited transactions with a transaction fee.
// Memoization Approach
// TC : O(N * 2) = O(N)
// SC : O(N * 2) + O(N) for recursion stack space
class Solution {
public:
    int solve(int ind, vector<int>& prices, int holding, vector<vector<int>>& dp, int fee) {
        if(ind >= prices.size()) {
            return 0;
        }

        if(dp[ind][holding] != -1)
            return dp[ind][holding];

        if(holding) 
            return dp[ind][holding] = max(prices[ind] + solve(ind + 1, prices, 0, dp, fee) - fee, solve(ind + 1, prices, 1, dp, fee));
        
        return dp[ind][holding] = max(-prices[ind] + solve(ind + 1, prices, 1, dp, fee), solve(ind + 1, prices, 0, dp, fee));
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices, 0, dp, fee);
    }
};

// Tabular Approach
// TC : O(N * 2) = O(N)
// SC : O(N * 2)
class Solution {
public: 
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int holding = 0; holding <= 1; holding++) {
                if(holding)
                    dp[ind][holding] = max(prices[ind] + dp[ind + 1][0] - fee, dp[ind + 1][1]);
                else
                    dp[ind][holding] = max(-prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
            }
        }

        return dp[0][0];
    }
};

// Simplified Tabular Approach
// TC : O(N)
// SC : O(N * 2) = O(N)
class Solution {
public: 
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            dp[ind][1] = max(prices[ind] + dp[ind + 1][0] - fee, dp[ind + 1][1]);
            dp[ind][0] = max(-prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
        }

        return dp[0][0];
    }
};

// Space Optimized Approach
// TC : O(N)
// SC : O(2) = O(1)
class Solution {
public: 
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> nextDay(2, 0), currDay(2, 0);
        
        for(int ind = n - 1; ind >= 0; ind--) {
            currDay[1] = max(prices[ind] + nextDay[0] - fee, nextDay[1]);
            currDay[0] = max(-prices[ind] + nextDay[1], nextDay[0]);

            nextDay = currDay;
        }

        return nextDay[0];
    }
};