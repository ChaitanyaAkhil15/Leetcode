// Problem Link : https://www.naukri.com/code360/problems/longest-common-substring_1214702?leftPanelTabValue=PROBLEM

// Memoization Approach
// TC : O(n * m)
// SC : O(n * m) + O(n + m)
int solve(int i, int j, vector<vector<int>>& dp, string& text1, string& text2) {
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i - 1, j - 1, dp, text1, text2);
        else
            return dp[i][j] = 0;
}

int LCSubStr(string &text1, string &text2)
{
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxLength = 0;
    
    // Try every possible ending position - this is the key change!
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            maxLength = max(maxLength, solve(i, j, dp, text1, text2));
        }
    }
    
    return maxLength;
}

// Tabular Approach
// TC : O(n * m)
// SC : O(n * m)
int LCSubStr(string &text1, string &text2)
{
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    
    return ans;

}

// Space Optimized Approach
// TC : O(n * m)
// SC : O(m)
int LCSubStr(string &text1, string &text2)
{
    int n = text1.length(), m = text2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
            else {
                curr[j] = 0;
            }
        }

        prev = curr;
    }
    
    return ans;

}