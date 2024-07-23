/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.89%)
 * Likes:    21611
 * Dislikes: 660
 * Total Accepted:    1.3M
 * Total Submissions: 3M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * subarrays whose sum equals to k.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSumMap;
        int idx = 0;
        int count = 0, currentSum = 0;

        prefixSumMap[0] = 1;
        while(idx < n)
        {
            currentSum += nums[idx];
            count+=prefixSumMap[currentSum - k];
            prefixSumMap[currentSum]++;
            // if(prefixSumMap.find(currentSum - k) != prefixSumMap.end()) 
            idx++;
        }

        return count;
    }
};
// @lc code=end

