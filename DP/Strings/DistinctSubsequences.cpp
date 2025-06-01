// Problem Link : https://leetcode.com/problems/distinct-subsequences/

// Memoization Approach
// TC : O(n * m)
// SC : O(n * m) + O(n + m) for recursion stack space
class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(j < 0)
            return 1;

        if(i < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j]) {
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
        }

        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(n - 1, m - 1, s, t, dp);
    }
};

// Tabulation Approach
// TC : O(n * m)
// SC : O(n * m)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(m + 1, 0));
        
        for(int i = 0; i <= n; i++) 
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][m];
    }
};

// Space Optimized 1-D Approach
// TC : O(n * m)
// SC : O(m)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<uint64_t> dp(m + 1, 0);

        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= 1; j--) {
                if(s[i - 1] == t[j - 1])
                    dp[j] = dp[j - 1] + dp[j];
            }
        }

        return dp[m];
    }
};