// problem link : https://leetcode.com/problems/burst-balloons

// Memoization 
// TC : O(N ^ 3)
// SC : O(N ^ 2) + O(N) recursion stack space
class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int max_coins = INT_MIN;
        for(int ind = i; ind <= j; ind++) {
            int coins = nums[i - 1] * nums[ind] * nums[j + 1] + solve(i, ind - 1, nums, dp) 
                        + solve(ind + 1, j, nums, dp);
            max_coins = max(max_coins, coins);
        }

        return dp[i][j] = max_coins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, nums, dp);
    }
};

// Tabulation Approach
// TC : O(N ^ 3)
// SC : O(N ^ 2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i = n; i >= 1; i--) {
            for(int j = i; j <= n; j++) {
                int max_coins = INT_MIN;
                for(int ind = i; ind <= j; ind++) {
                    int coins = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] 
                                + dp[ind + 1][j];
                    max_coins = max(max_coins, coins);
                }

                dp[i][j] = max_coins;                
            }
        }

        return dp[1][n];
    }
};