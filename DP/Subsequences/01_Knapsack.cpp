// Problem Link : https://www.naukri.com/code360/problems/0-1-knapsack_920542?leftPanelTabValue=PROBLEM

// Memoization Approach
// TC : O(n * maxWeight)
// SC : O(n * maxWeight) + O(n)
#include <bits/stdc++.h> 
int solve(vector<int> weight, vector<int> value, int ind, vector<vector<int>>& dp, int currWeight) {
	if(currWeight == 0)
		return 0;
	
	if(ind == 0) {
		if(weight[0] <= currWeight)
			return value[0];
		return 0;
	}

	if(dp[ind][currWeight] != -1)
		return dp[ind][currWeight];
	
	int pick = INT_MIN;
	if(weight[ind] <= currWeight)
		pick = value[ind] + solve(weight, value, ind - 1, dp, currWeight - weight[ind]);
	
	int notPick = solve(weight, value, ind - 1, dp, currWeight);

	return dp[ind][currWeight] = max(pick, notPick);
}


// Tabulation Approach
// TC : O(n * maxWeight)
// SC : O(n * maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	for(int ind = 0; ind < n; ind++)
        dp[ind][0] = 0;
	
	for(int currWeight = 1; currWeight <= maxWeight; currWeight++) {
		if(weight[0] <= currWeight)
			dp[0][currWeight] = value[0];
		else
			dp[0][currWeight] = 0;
	}

	for(int ind = 1; ind < n; ind++) {
		for(int currWeight = 1; currWeight <= maxWeight; currWeight++) {
			int pick = INT_MIN;

			if(weight[ind] <= currWeight)
				pick = value[ind] + dp[ind - 1][currWeight - weight[ind]];
			
			int notPick = dp[ind - 1][currWeight];

			dp[ind][currWeight] = max(pick, notPick);
		}
	}

	return dp[n - 1][maxWeight];
}

// Space Optimized Approach
// TC : O(n * maxWeight)
// SC : O(2 * maxWeight)
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight + 1, 0);
	vector<int> curr(maxWeight + 1, 0);
	
	for(int currWeight = 1; currWeight <= maxWeight; currWeight++) {
		if(weight[0] <= currWeight)
			prev[currWeight] = value[0];
		else
			prev[currWeight] = 0;
	}

	for(int ind = 1; ind < n; ind++) {
		for(int currWeight = 1; currWeight <= maxWeight; currWeight++) {
			int pick = INT_MIN;

			if(weight[ind] <= currWeight)
				pick = value[ind] + prev[currWeight - weight[ind]];
			
			int notPick = prev[currWeight];

			curr[currWeight] = max(pick, notPick);
		}
		prev = curr;
	}

	return prev[maxWeight];
}

// 1D Space Optimized Approach
// TC : O(n * maxWeight)
// SC : O(maxWeight)
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight + 1, 0);
	
	for(int currWeight = 1; currWeight <= maxWeight; currWeight++) {
		if(weight[0] <= currWeight)
			prev[currWeight] = value[0];
		else
			prev[currWeight] = 0;
	}

	for(int ind = 1; ind < n; ind++) {
		for(int currWeight = maxWeight; currWeight >= 0; currWeight--) {
			int pick = INT_MIN;

			if(weight[ind] <= currWeight)
				pick = value[ind] + prev[currWeight - weight[ind]];
			
			int notPick = prev[currWeight];

			prev[currWeight] = max(pick, notPick);
		}
	}

	return prev[maxWeight];
}


