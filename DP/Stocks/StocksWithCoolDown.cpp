// problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

// This problem is a variant of Stocks2.cpp, in Stocks2 we are allowed to make unlimited transactions, while here we can only make unlimited transactions with a cooldown period of 1 day after selling a stock.
// Memoization Approach
// TC : O(N * 2) = O(N)
// SC : O(N * 2) + O(N) for recursion stack space
class Solution {
public:
    int solve(int ind, vector<int>& prices, int holding, vector<vector<int>>& dp) {
        if(ind >= prices.size()) {
            return 0;
        }

        if(dp[ind][holding] != -1)
            return dp[ind][holding];

        if(holding) 
            return dp[ind][holding] = max(prices[ind] + solve(ind + 2, prices, 0, dp), solve(ind + 1, prices, 1, dp));
        
        return dp[ind][holding] = max(-prices[ind] + solve(ind + 1, prices, 1, dp), solve(ind + 1, prices, 0, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices, 0, dp);
    }
};

// Tabular Approach
// TC : O(N * 2) = O(N)
// SC : O(N * 2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int holding = 0; holding <= 1; holding++) {
                if(holding)
                    dp[ind][holding] = max(prices[ind] + dp[ind + 2][0], dp[ind + 1][1]);
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            dp[ind][1] = max(prices[ind] + dp[ind + 2][0], dp[ind + 1][1]);
            dp[ind][0] = max(-prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
        }

        return dp[0][0];
    }
};

// Space Optimized Approach
// TC : O(N)
// SC : O(3 * 2) = O(1)
// since there is an ind + 2, we need to store the next day and the day after that values, thus we can use three arrays to store the current, next and nextnext day values.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> nextnextDay(2, 0), nextDay(2, 0), currDay(2, 0);

        for(int ind = n - 1; ind >= 0; ind--) {
            currDay[1] = max(prices[ind] + nextnextDay[0], nextDay[1]);
            currDay[0] = max(-prices[ind] + nextDay[1], nextDay[0]);

            nextnextDay = nextDay;
            nextDay = currDay;
        }

        return nextDay[0];
    }
};