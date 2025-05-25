// Problem Link : https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628?leftPanelTabValue=PROBLEM
// Since we need to partition the array into two subsets such that the absolute difference of their sums is equal to d,
// we can transform this problem into a subset sum problem.
// The idea is to find a subset with sum equal to (totalSum - d) / 2.
// If we can find such a subset, then the other subset will have sum equal to (totalSum + d) / 2.

// Why (totalSum - d) / 2 ?
// Let's say we have two subsets S1 and S2 with sums sum1 and sum2 respectively.
// We know that sum1 - sum2 = d.
// Substituting sum1 as totSum - sum2 and vice-versa and Rearranging gives us sum1 = (totalSum + d) / 2 and sum2 = (totalSum - d) / 2

// Memoization Approach
// TC : O(n * totSum)
// SC : O(n * totSum) + O(n)
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

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    int mod = 1e9 + 7;

    for(auto &ele : arr)
        totSum += ele;
    
    if(totSum - d < 0 || (totSum - d) & 1)
        return 0;

    int sumToFind = (totSum - d) / 2;

    vector<vector<int>> dp(n, vector<int> (sumToFind + 1, -1));
    
    return solve(arr, n - 1, dp, sumToFind, mod);
}

// Tabulation Approach
// TC : O(n * totSum)
// SC : O(n * totSum)
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    int mod = 1e9 + 7;

    for(auto &ele : arr)
        totSum += ele;
    
    if(totSum - d < 0 || (totSum - d) & 1)
        return 0;

    int sumToFind = (totSum - d) / 2;
    
    vector<vector<int>> dp(n, vector<int>(sumToFind + 1, 0));

	if(arr[0] == 0)
        dp[0][0] = 2; // Two ways to choose nothing (Pick or Not Pick)
    else
        dp[0][0] = 1; // One way to choose nothing (Not Pick)
    
    if(arr[0] <= k && arr[0] != 0) dp[0][arr[0]] = 1; // One way to choose the first element if it equals k

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= sumToFind; sum++) {
            int pick = 0;
            if(arr[ind] <= sum)
                pick = dp[ind - 1][sum - arr[ind]] % mod;

            int notPick = dp[ind - 1][sum] % mod;

            dp[ind][sum] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][sumToFind];
}

// Space Optimized Approach
// TC : O(n * totSum)
// SC : O(totSum)
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    int mod = 1e9 + 7;

    for(auto &ele : arr)
        totSum += ele;
    
    if(totSum - d < 0 || (totSum - d) & 1)
        return 0;

    int sumToFind = (totSum - d) / 2;
    
    vector<int> prev(sumToFind + 1, 0);
    
    if(arr[0] == 0)
        prev[0] = 2; // Two ways to choose nothing (Pick or Not Pick)
    else
        prev[0] = 1; // One way to choose nothing (Not Pick)
    
    if(arr[0] <= sumToFind && arr[0] != 0) prev[arr[0]] = 1; // One way to choose the first element if it equals k

    for(int ind = 1; ind < n; ind++) {
        vector<int> curr(sumToFind + 1, 0);
        for(int sum = 0; sum <= sumToFind; sum++) {
            int pick = 0;
            if(arr[ind] <= sum)
                pick = prev[sum - arr[ind]] % mod;

            int notPick = prev[sum] % mod;

            curr[sum] = (pick + notPick) % mod;
        }
        prev = curr;
    }
    return prev[sumToFind];
}





