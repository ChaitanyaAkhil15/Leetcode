/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start

// ***** Note : 2nd approach ******
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        long long curr = 0;

        int left = 0, right = 0;
        while(right < N)
        {
            curr += nums[right];
            if(((long)(right - left + 1) * nums[right] - curr) > k)
                curr -= nums[left++];
            
            right++;
        }

        return N-left;
    }
};
// @lc code=end

