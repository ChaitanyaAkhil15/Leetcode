// Problem Link : https://leetcode.com/problems/longest-common-subsequence/

// Memoization Approach
// TC : O(n * m)
// SC : O(n * m) + O(n + m)
// The Auxiliary Stack Space or the Recursion Depth is O(n + m) in the worst case because at each level
// we are elementarily reducing either the index of text1 or text2, leading to a maximum depth of n + m.
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, string& text1, string& text2) {
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j])
            return 1 + solve(i - 1, j - 1, dp, text1, text2);
        
        return dp[i][j] = max(solve(i - 1, j, dp, text1, text2), solve(i, j - 1, dp, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, dp, text1, text2);
    }
};

// Tabulation Approach
// TC : O(n * m)
// SC : O(n * m)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[n][m];
    }
};

// Space Optimized Approach
// TC : O(n * m)
// SC : O(m)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }
        
        return prev[m];
    }
};