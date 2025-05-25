// Problem Link : https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM

// Memoization Approach
//  TC : O(n * k)
//  SC : O(n * k) + O(n)
int solve(vector<int>& arr, int ind, vector<vector<int>> &dp, int k, int mod) {
	if(ind == 0) {
		if(k == 0 && arr[0] == 0)
			return 2;
		if(k == 0 || arr[0] == k)
			return 1;

		return 0;
	}

	if(dp[ind][k] != -1)
		return dp[ind][k];
		
	int pick = 0;
	if(arr[ind] <= k)
		pick = solve(arr, ind - 1, dp, k - arr[ind], mod) % mod;

	int notPick = solve(arr, ind - 1, dp, k, mod) % mod;

	return dp[ind][k] = (pick + notPick) % mod;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	int mod = 1e9 + 7;
	vector<vector<int>> dp(n, vector<int>(k + 1, -1));

	return solve(arr, arr.size() - 1, dp, k, mod);	
}

// Tabulation Approach
// TC : O(n * k)
// SC : O(n * k)
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	int mod = 1e9 + 7;
	vector<vector<int>> dp(n, vector<int>(k + 1, 0));

	if(arr[0] == 0)
        dp[0][0] = 2; // Two ways to choose nothing (Pick or Not Pick)
    else
        dp[0][0] = 1; // One way to choose nothing (Not Pick)
    
    if(arr[0] <= k && arr[0] != 0) dp[0][arr[0]] = 1; // One way to choose the first element if it equals k

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= k; sum++) {
            int pick = 0;
            if(arr[ind] <= sum)
                pick = dp[ind - 1][sum - arr[ind]] % mod;

            int notPick = dp[ind - 1][sum] % mod;

            dp[ind][sum] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][k];
}

// Space Optimized Approach
// TC : O(n * k)
// SC : O(k)
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    int mod = 1e9 + 7;
    vector<int> prev(k + 1, 0);

    if(arr[0] == 0)
        prev[0] = 2; // Two ways to choose nothing (Pick or Not Pick)
    else
        prev[0] = 1; // One way to choose nothing (Not Pick)
    
    if(arr[0] <= k && arr[0] != 0) prev[arr[0]] = 1; // One way to choose the first element if it equals k

    for(int ind = 1; ind < n; ind++) {
        vector<int> curr(k + 1, 0);
        for(int sum = 0; sum <= k; sum++) {
            int pick = 0;
            if(arr[ind] <= sum)
                pick = prev[sum - arr[ind]] % mod;

            int notPick = prev[sum] % mod;

            curr[sum] = (pick + notPick) % mod;
        }
        prev = curr;
    }
    return prev[k];
}