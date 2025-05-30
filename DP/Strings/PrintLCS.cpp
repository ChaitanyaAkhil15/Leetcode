// Problem Link : https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM
// Phase 1 : Finding length of Longest Common Subsequence
// Phase 2 : Backtracking to find the actual LCS string

// Complexity Analysis
// Time Complexity: O(n × m)

// Phase 1 requires filling an (n+1) × (m+1) table: O(n × m)
// Phase 2 requires traversing at most n + m cells: O(n + m)
// Overall: O(n × m)

// Space Complexity: O(n × m)

// We need an (n+1) × (m+1) DP table
// The result string takes O(min(n, m)) space in the worst case

// Phase 2: Reconstructing the Actual String (Backtracking)
// Once we know the optimal length, we need to figure out which characters actually form the LCS. We do this by retracing our steps through the DP table, starting from the bottom-right corner.
// The backtracking logic mirrors our original decision process:

// If characters match, they must be part of our LCS
// If they don't match, we follow the path that led to the larger value in our DP table

string longestCommonSubsequence(string text1, string text2) {
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

		int len = dp[n][m];
		
		string ans(len, '$');

		int i = n, j = m, ind = len - 1;
		while(i > 0 && j > 0) {
			if(text1[i - 1] == text2[j - 1]) {
				ans[ind] = text1[i - 1];
				ind--;
				i--;
				j--;
			}
			else if(dp[i - 1][j] > dp[i][j - 1]) {
				i = i - 1;
			}
			else {
				j = j - 1;
			}
		}
        
        return ans;
}