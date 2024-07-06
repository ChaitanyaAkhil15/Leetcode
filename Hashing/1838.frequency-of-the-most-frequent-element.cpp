/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int ans = 1;
        long long curr = 0;

        int left = 0, right = 0;
        while(right < N)
        {
            curr += nums[right];
            while(((long)(right - left + 1) * nums[right] - curr) > k)
                curr -= nums[left++];
            
            ans = max(ans, (right - left + 1));
            right++;
        }

        return ans;
    }
};
// @lc code=end

