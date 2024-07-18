/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (59.65%)
 * Likes:    5737
 * Dislikes: 456
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * Given a binary array nums, return the maximum number of consecutive 1's in
 * the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s. The maximum number of consecutive 1s is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx_count = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                count++;
            else
                count = 0;

            mx_count = max(mx_count, count); 
        }

        return mx_count;
    }
};
// @lc code=end

