// problem link : https://leetcode.com/problems/longest-increasing-subsequence

// Memoization Approach
// TC : O(N * N);
// SC : O(N * N) + O(N)
int solve(int ind, vector<int>& nums, int lastInd, vector<vector<int>>& dp) {
    if(ind >= nums.size())
        return 0;
    
    if(dp[ind][lastInd + 1] != -1)
        return dp[ind][lastInd + 1];

    int pick = INT_MIN;
    if(lastInd == -1 || nums[ind] > nums[lastInd]) 
        pick = 1 + solve(ind + 1, nums, ind, dp);
    
    int notPick = solve(ind + 1, nums, lastInd, dp);

    return dp[ind][lastInd + 1] = max(pick, notPick);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(0, nums, -1, dp);
}

// Tabular Approach
// TC : O(N * N);
// SC : O(N * N)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int ind = n - 1; ind >= 0; ind--) {
        for(int lastInd = n - 1; lastInd >= -1; lastInd--) {
            int pick = INT_MIN;
            if(lastInd == -1 || nums[ind] > nums[lastInd]) 
                pick = 1 + dp[ind + 1][ind + 1];
            
            int notPick = dp[ind + 1][lastInd + 1];

            dp[ind][lastInd + 1] = max(pick, notPick);
        }
    }

    return dp[0][0];
}

// Space Optimized Approach
// TC : O(N * N);
// SC : O(N) 
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    for(int ind = n - 1; ind >= 0; ind--) {
        for(int lastInd = n - 1; lastInd >= -1; lastInd--) {
            int pick = INT_MIN;
            if(lastInd == -1 || nums[ind] > nums[lastInd]) 
                pick = 1 + next[ind + 1];
            
            int notPick = next[lastInd + 1];

            curr[lastInd + 1] = max(pick, notPick);
        }
        next = curr;
    }

    return next[0];
}

// Another Space Optimized Approach
// The idea is that each we calculate the maximum length of subsequence ending with an element at index i
// Initially maximum length of subsequence ending with an element at index i is 1
// we iterate through all the previous elements and if curr_ele > pre_ele then we can include that ele in our subsequence so we can simply do 1 + dp[i]
// TC : O(N * N)
// SC : O(N)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int mx = 1;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                mx = max(mx, dp[i]);
            }
        }
    }

    return mx;
} 

// Most Optimal Solution
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> tails;
    for(int i = 0; i < n; i++) {
        int num = nums[i];
        
        int left = 0, right = tails.size();
        while(left < right) {
            int mid = left + (right - left) / 2;

            if(tails[mid] < num)
                left = mid + 1;
            else
                right = mid;
        }

        if(left == tails.size())
            tails.push_back(num);
        else
            tails[left] = num;
    }

    return tails.size();
}