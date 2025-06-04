// problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

// This problem is a variant of Stocks3.cpp, in Stocks3 we are allowed to make at most 2 transactions, while here we can make at most k transactions.
// Memoization Approach
// TC : O(N * 2k) = O(N * k)
// SC : O(N * 2k) + O(N) for recursion stack space
class Solution {
public:
    int solve(int ind, vector<int>& prices, int transaction_count, vector<vector<int>>& dp, int k) {
        if(transaction_count == 2 * k)
            return 0;

        if(ind == prices.size())
            return 0;
        
        if(dp[ind][transaction_count] != -1)
            return  dp[ind][transaction_count];

        if(transaction_count % 2 == 0) {
            // else we can either buy or wait
            return dp[ind][transaction_count] = max(-prices[ind] + solve(ind + 1, prices, transaction_count + 1, dp, k), solve(ind + 1, prices, transaction_count, dp, k));
        }
        
        // we can sell the holding stock or wait
        return dp[ind][transaction_count] = max(prices[ind] + solve(ind + 1, prices, transaction_count + 1, dp, k), solve(ind + 1, prices, transaction_count, dp, k));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return solve(0, prices, 0, dp, k);
    }
};

// Tabular Approach
// TC : O(N * 2k) = O(N * k)
// SC : O(N * 2k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int transaction_count = 2 * k - 1; transaction_count >= 0; transaction_count--) {
                if(transaction_count % 2 == 0)
                    dp[ind][transaction_count] = max(-prices[ind] + dp[ind + 1][transaction_count + 1], dp[ind + 1][transaction_count]);
                else
                    dp[ind][transaction_count] = max(prices[ind] + dp[ind + 1][transaction_count + 1], dp[ind + 1][transaction_count]);
            }
        }

        return dp[0][0];
    }
};

// Space Optimized Approach
// TC : O(N * 2k) = O(N * k)
// SC : O(2k) = O(k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> nextDay(2 * k + 1, 0), currDay(2 * k + 1, 0);

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int transaction_count = 2 * k - 1; transaction_count >= 0; transaction_count--) {
                if(transaction_count % 2 == 0)
                    currDay[transaction_count] = max(-prices[ind] + nextDay[transaction_count + 1], nextDay[transaction_count]);
                else
                    currDay[transaction_count] = max(prices[ind] + nextDay[transaction_count + 1], nextDay[transaction_count]);
            }
            nextDay = currDay;
        }

        return nextDay[0];
    }
};