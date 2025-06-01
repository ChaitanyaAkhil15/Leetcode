// Problem Link : https://leetcode.com/problems/edit-distance/description/

// Memoization Approach
// TC : O(n * m)
// SC : O(n * m) + O(n + m) for recursion stack space
class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if(j < 0)
            return i + 1;
        
        if(i < 0)
            return j + 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j]) {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        }
        
        int insert = 1 + solve(i, j - 1, word1, word2, dp);
        int del = 1 + solve(i - 1, j, word1, word2, dp);
        int replace = 1 + solve(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = min(insert, min(del, replace));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, word1, word2, dp);
    }
};

// Tabulation Approach
// TC :O(n * m)
// SC : O(n * m)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for(int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }

        return dp[n][m];
    }
};

// Space Optimized Approach
// TC :O(n * m)
// SC : O(m)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for(int j = 1; j <= m; j++) {
            prev[j] = j;
        }

        for(int i = 1; i <= n; i++){
            curr[0] = i;
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else 
                    curr[j] = 1 + min(curr[j - 1], min(prev[j], prev[j - 1]));
            }
            prev = curr;
        }

        return prev[m];
    }
};