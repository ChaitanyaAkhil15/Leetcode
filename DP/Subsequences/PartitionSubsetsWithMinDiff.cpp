// problem link : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference
// In this problem we need to partition the array into two subsets such that the absolute difference of their sums is minimized.
// The Catch is we need to partition the two subsets of size n/2 each.
// For this we can follow the PartitionSubsetsWithEqualSum approach by introducing a new variable to keep track of the size of the subsets.
// But then the time complexity will be O(n^2 * k) and space complexity will be O(n^2 * k).
// we will try another approach called Meet in the middle.

// The idea is to split the array into two halves and find all possible subset sums for each half.
// Code to find all possible subset sums for one half

// Explanation : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/2850095/c-first-timers-explanation-meet-in-middle-simplest-code/

vector<vector<int>> generateSubsetSums(int l, int r, vector<int>& nums) {
    int n = r - l + 1;
    vector<vector<int>> sums(n + 1);

    for(int i = 0; i < (1 << n); i++) {
        int sz = 0;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sz++;
                sum += nums[l + j];
            }
        }

        sums[sz].push_back(sum);
    }

    return sums;
}

int minimumDifference(vector<int>& nums) {
    int totSum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();

    auto left = generateSubsetSums(0, n / 2 - 1, nums);
    auto right = generateSubsetSums(n / 2,  n - 1, nums);
    int target = totSum / 2;
    int ans = INT_MAX;

    for(int i = 0; i <= n / 2; i++) {
        auto r = right[n / 2 - i];
        sort(begin(r), end(r));

        for(int curr : left[i]) {
            int sumFromRight = target - curr;
            auto it = lower_bound(begin(r), end(r), sumFromRight);

            if(it != end(r))
                ans = min(ans, abs(totSum - 2 * (curr + *it)));
        }
    }

    return ans;
}
