// Problem Link : https://www.naukri.com/code360/problems/rod-cutting-problem_800284?leftPanelTabValue=PROBLEM

// Memoization Approach
// TC : O(n * n)
// SC : O(n * n) + O(n)
int solve(int ind, int currLength, vector<vector<int>>& dp, vector<int>& price) {
	if(currLength == 0)
		return 0;
	
	if(ind == 0)
		return (currLength / (ind + 1)) * price[0];

	if(dp[ind][currLength] != -1)
		return dp[ind][currLength];
		
	int pick = INT_MIN;
	if(ind + 1 <= currLength)
		pick = price[ind] + solve(ind, currLength - (ind + 1), dp, price);
	
	int notPick = solve(ind - 1, currLength, dp, price);

	return dp[ind][currLength] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n + 1, -1));

	return solve(n - 1, n, dp, price);
}

// Tabulation Approach
// TC : O(n * n)
// SC : O(n * n)
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n + 1, 0));

	for(int length = 0; length <= n; length++) {
		dp[0][length] = length * price[0];
	}

	for(int ind = 1; ind < n; ind++) {
		for(int length = 0; length <= n; length++) {
			int pick = INT_MIN;
			if(ind + 1 <= length)
				pick = price[ind] + dp[ind][length - (ind + 1)];
			
			int notPick = dp[ind - 1][length];

			dp[ind][length] = max(pick, notPick);
		}
	}

	return dp[n - 1][n];
}

// 1D Space Optimized Approach
// TC : O(n * n)
// SC : O(n)
// The Space Optimization is similar to the Unbounded Knapsack problem.
int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n + 1, 0);

	for(int length = 0; length <= n; length++) {
		dp[length] = length * price[0];
	}

	for(int ind = 1; ind < n; ind++) {
		for(int length = ind + 1; length <= n; length++) {
			dp[length] = max(price[ind] + dp[length - (ind + 1)], dp[length]);
		}
	}

	return dp[n];
}

