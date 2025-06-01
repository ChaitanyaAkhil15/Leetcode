// Problem Link : https://www.naukri.com/code360/problems/shortest-supersequence_4244493?leftPanelTabValue=PROBLEM
// This problem is a variant of Longest Common Subsequence, we have to use the dp table to reconstruct the shortest supersequence.

// Optimized Approach
// TC : O(n * m)
// SC : O(n * m)
// i - 1 and j - 1 in character comparison is because we are using 1-based indexing in the dp table.
#include <bits/stdc++.h> 
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
	
	string ans = "";

	int i = n, j = m;
	while(i > 0 && j > 0) {
		if(text1[i - 1] == text2[j - 1]) {
			ans += text1[i - 1];
			i--;
			j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1]) { // if we are going up in the table we will miss the ith character of text1, so we add it to answer.
			ans += text1[i - 1];
			i = i - 1;
		}
		else {
			ans += text2[j - 1]; // same here, if we are going left in the table we will miss the jth character of text2, so we add it to answer.
			j = j - 1;
		}
	}
	
    // what if there are remaining characters in text1
	while(i > 0) {
		ans += text1[i - 1];
		i--;
	}

    // what if there are remaining characters in text2
	while(j > 0) {
		ans += text2[j - 1];
		j--;
	}

    // since we are constructing the string from the end, we need to reverse it
	reverse(ans.begin(), ans.end());
	return ans;
}


string shortestSupersequence(string a, string b)
{
	return longestCommonSubsequence(a, b);
}