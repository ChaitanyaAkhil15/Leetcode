// problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

// Memoization Approach
// TC : O(N)
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
            return dp[ind][holding] = max(prices[ind] + solve(ind + 1, prices, 0, dp), solve(ind + 1, prices, 1, dp));
        
        return dp[ind][holding] = max(-prices[ind] + solve(ind + 1, prices, 1, dp), solve(ind + 1, prices, 0, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices, 0, dp);
    }
};

// Tabular Approach
// TC : O(N)
// SC : O(N * 2)
// Note: In the next optimization we can omit the inner loop, as both the dp statements get executed anyways.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = 0, dp[n][1] = 0;
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int holding = 0; holding <= 1; holding++) {
                if(holding)
                    dp[ind][holding] = max(prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                else
                    dp[ind][holding] = max(-prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
            }
        }

        return dp[0][0];
    }
};

// Space Optimized Approach
// TC : O(N)
// SC : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int nextNotBuy, nextBuy;
        nextNotBuy = 0, nextBuy = 0;
        for(int ind = n - 1; ind >= 0; ind--) {
            int currBuy = max(prices[ind] + nextNotBuy, nextBuy);
            int currNotBuy = max(-prices[ind] + nextBuy, nextNotBuy);

            nextBuy = currBuy;
            nextNotBuy = currNotBuy;
        }

        return nextNotBuy;
    }
};

// Two Variable Approach
// TC : O(N)
// SC : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int nextNotBuy = 0, nextBuy = 0;
        for(int ind = n - 1; ind >= 0; ind--) {
            nextBuy = max(prices[ind] + nextNotBuy, nextBuy);;
            nextNotBuy = max(-prices[ind] + nextBuy, nextNotBuy);
        }

        return nextNotBuy;
    }
};

// Greedy Approach
// TC : O(N)
// SC : O(1)
// Think about this, we need to maximize the profit, consider a graph plot, if we only consider the upward slopes, we can get the maximum profit by buying at the start of the upward slope and selling at the end of it.
// when a downward slope is encountered, we can just ignore it and continue to the next upward slope.
// In this code, I'm not considering the start of the upward slope, but rather just adding the difference between the current price and the previous price if the current price is greater than the previous price.
// This will eventually be the same as buying at the start of the upward slope and selling at the end of it.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }

        return profit;
    }
};