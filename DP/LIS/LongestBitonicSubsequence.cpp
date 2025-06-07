// problem link : https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688?leftPanelTabValue=PROBLEM

// This is a variant of LIS, we compute LIS length in forward manner(This gives us length of longest increasing subsequence)
// we also compute LIS from the end, this will give us (longest decreasing subsequence)
// In the end, we check both dp arrays for each index, and calculate the length of longest bitonic subsequence we can form at that index and then find the maximum among them
int longestBitonicSubsequence(vector<int>& nums, int n)
{
	vector<int> dp1(n, 1), dp2(n, 1);
	int mx = 1;

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(nums[j] < nums[i] && 1 + dp1[j] > dp1[i]) {
				dp1[i] = 1 + dp1[j];
			}
				
			mx = max(mx, dp1[i]);
		}
	}

	for(int i = n - 2; i >= 0; i--) {
		for(int j = n - 1; j > i; j--) {
			if(nums[j] < nums[i] && 1 + dp2[j] > dp2[i]) {
				dp2[i] = 1 + dp2[j];
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		mx = max(mx, dp1[i] + dp2[i] - 1);
	}

	return mx;
}
