// problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

// This is a variant of Stocks2.cpp, in Stocks2 we are allowed to make unlimited transactions, while here we can only make at most 2 transactions.
// So we need another parameter to keep track of the number of transactions left.
// Memoization Approach
// TC : O(N * 3 * 2) = O(N)
// SC : O(N * 3 * 2) + O(N) for recursion stack space
class Solution {
public:
    int solve(int ind, vector<int>& prices, int transactions_left, int holding, vector<vector<vector<int>>>& dp) {
        if(transactions_left == 0)
            return 0;

        if(ind == prices.size())
            return 0;
        
        if(dp[ind][transactions_left][holding] != -1)
            return  dp[ind][transactions_left][holding];

        if(holding) {
            // we can sell the holding stock or wait
            return dp[ind][transactions_left][holding] = max(prices[ind] + solve(ind + 1, prices, transactions_left - 1, 0, dp), solve(ind + 1, prices, transactions_left, 1, dp));
        }
        
        // else we can either buy or wait
        return dp[ind][transactions_left][holding] = max(-prices[ind] + solve(ind + 1, prices, transactions_left, 1, dp), solve(ind + 1, prices, transactions_left, 0, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(0, prices, 2, 0, dp);
    }
};

// Tabular Approach
// TC : O(N * 3 * 2) = O(N)
// SC : O(N * 3 * 2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, 0)));


        for(int ind = n - 1; ind >= 0; ind--) {
            for(int transactions_left = 1; transactions_left <= 2; transactions_left++) {
                for(int holding = 0; holding <= 1; holding++) {
                    if(holding)
                        dp[ind][transactions_left][holding] = max(prices[ind] + dp[ind + 1][transactions_left - 1][0], dp[ind + 1][transactions_left][1]);
                    else
                        dp[ind][transactions_left][holding] = max(-prices[ind] + dp[ind + 1][transactions_left][1], dp[ind + 1][transactions_left][0]);
                }
            }
        }

        return dp[0][2][0];
    }
};

// Space Optimized Approach
// TC : O(N * 3 * 2) = O(N)
// SC : O(3 * 2) = O(1)
// Here since we only need the next day values, we can use two arrays to store the current and next day values, thus reducing the space complexity.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> nextDay(3, vector<int>(2, 0));
        vector<vector<int>> currDay(3, vector<int>(2, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int transactions_left = 1; transactions_left <= 2; transactions_left++) {
                for(int holding = 0; holding <= 1; holding++) {
                    if(holding)
                        currDay[transactions_left][holding] = max(prices[ind] + nextDay[transactions_left - 1][0], nextDay[transactions_left][1]);
                    else
                        currDay[transactions_left][holding] = max(-prices[ind] + nextDay[transactions_left][1], nextDay[transactions_left][0]);
                }
            }
            nextDay = currDay;
        }

        return nextDay[2][0];
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

// Another approach is to use a O(N * 4) size dp array
// The idea here is we can have a total of 4 different transaction states:
// Buy 1, Sell 1, Buy 2, Sell 2
// We can represent these states as follows:
// 0 - Buy 1st stock (compare this to the top solution where holding = 0, since holding is 0 we buy the stock)
// 1 - Sell 1st stock (compare this to the top solution where holding = 1, since holding is 1 we sell the stock)
// 2 - Buy 2nd stock
// 3 - Sell 2nd stock
// so even indices indicate buying and odd indices indicate selling.
// Memoization Approach
// TC : O(N * 4) = O(N)
// SC : O(N * 4) + O(N) for recursion stack space
class Solution {
public:
    int solve(int ind, vector<int>& prices, int transaction_count, vector<vector<int>>& dp) {
        if(transaction_count == 4)
            return 0;

        if(ind == prices.size())
            return 0;
        
        if(dp[ind][transaction_count] != -1)
            return  dp[ind][transaction_count];

        if(transaction_count % 2 == 0) {
            // else we can either buy or wait
            return dp[ind][transaction_count] = max(-prices[ind] + solve(ind + 1, prices, transaction_count + 1, dp), solve(ind + 1, prices, transaction_count, dp));
        }
        
        // we can sell the holding stock or wait
        return dp[ind][transaction_count] = max(prices[ind] + solve(ind + 1, prices, transaction_count + 1, dp), solve(ind + 1, prices, transaction_count, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(0, prices, 0, dp);
    }
};

// Tabular Approach
// TC : O(N * 4) = O(N)
// SC : O(N * 4)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int transaction_count = 3; transaction_count >= 0; transaction_count--) {
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
// TC : O(N * 4) = O(N)
// SC : O(4) = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(5, 0), curr(5, 0);
        
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int transaction_count = 3; transaction_count >= 0; transaction_count--) {
                if(transaction_count % 2 == 0)
                    curr[transaction_count] = max(-prices[ind] + next[transaction_count + 1], next[transaction_count]);
                else
                    curr[transaction_count] = max(prices[ind] + next[transaction_count + 1], next[transaction_count]);
            }
            next = curr;
        }

        return next[0];
    }
};
