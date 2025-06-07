// problem link : https://leetcode.com/problems/largest-divisible-subset

// This is a variant of LIS, since we need to find a subset, we sort the arr to make it LIS.
// if the prev element (arr[j]) divides arr[i], then we add one to the subsequence length ending at arr[j] and compare it with dp[i]
// Optimal approach
// TC : O(N * N)
// SC : O(N)
vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int lastIndex = 0;
    int mx = 1;

    for(int i = 0; i < n; i++)
        hash[i] = i;
        
    sort(nums.begin(), nums.end());
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }

        if(dp[i] > mx) {
            mx = dp[i];
            lastIndex = i;
        }
    }

    ans.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex) { 
        lastIndex = hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}