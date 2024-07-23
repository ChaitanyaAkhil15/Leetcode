/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (50.93%)
 * Likes:    34041
 * Dislikes: 1445
 * Total Accepted:    4.1M
 * Total Submissions: 8M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the subarray with the largest sum, and
 * return its sum.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long int sum = 0;
        int mx_sum = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            if(sum > mx_sum)
                mx_sum = sum;
            
            if(sum < 0)
                sum = 0;
        }

        return mx_sum;
    }
};
// @lc code=end

