// Problem Link : https://leetcode.com/problems/wildcard-matching

// Memoization approach
// TC: O(n * m)
// SC: O(n * m) for dp array + O(n + m) for recursion stack space
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(j < 0 && i < 0)
            return true;

        if(j < 0)
            return false;

        if(i < 0) {
            int ind = j;
            while(ind >= 0) {
                if(p[ind] != '*')
                    return false;
                ind--;
            }
            return true;
        }

        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        else if(p[j] == '*')
            return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
        
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, s, p, dp);
    }
};

// Tabulation approach
// TC: O(n * m)
// SC: O(n * m) for dp array
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for(int i = 1; i <=n; i++)
            dp[i][0] = false;
        
        int ind = 1;
        while(ind <= m && p[ind - 1] == '*') {
            dp[0][ind] = true;
            ind++;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};

// Space Optimized Approach
// TC: O(n * m)
// SC: O(m) for dp array
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;
    
        int ind = 1;
        while(ind <= m && p[ind - 1] == '*') {
            prev[ind] = true;
            ind++;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')
                    curr[j] = curr[j - 1] || prev[j];
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};