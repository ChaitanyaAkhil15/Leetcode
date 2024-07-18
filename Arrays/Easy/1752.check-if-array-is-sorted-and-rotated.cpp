/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 *
 * https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
 *
 * algorithms
 * Easy (51.11%)
 * Likes:    3098
 * Dislikes: 166
 * Total Accepted:    251.5K
 * Total Submissions: 491.6K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Given an array nums, return true if the array was originally sorted in
 * non-decreasing order, then rotated some number of positions (including
 * zero). Otherwise, return false.
 * 
 * There may be duplicates in the original array.
 * 
 * Note: An array A rotated by x positions results in an array B of the same
 * length such that A[i] == B[(i+x) % A.length], where % is the modulo
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,4,5,1,2]
 * Output: true
 * Explanation: [1,2,3,4,5] is the original sorted array.
 * You can rotate the array by x = 3 positions to begin on the the element of
 * value 3: [3,4,5,1,2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,1,3,4]
 * Output: false
 * Explanation: There is no sorted array once rotated that can make nums.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: true
 * Explanation: [1,2,3] is the original sorted array.
 * You can rotate the array by x = 0 positions (i.e. no rotation) to make
 * nums.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int  n = nums.size();
        int count = 0;

        //We return true only in two cases
        //1. if the array is sorted and unrotated
        //2. if the array is sorted and rotated
        // For the 1st case arr[n - 1] >= arr[0]
        // For the 2nd case there will be one break in asc order

        //So we can increment count whenever there is a break in asc order
        //and by using (i+1)%n we even compare last element is first element
        //the count in both the cases mentioned above cannot exceed 1

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > nums[(i + 1) % n])
                count++;
        }

        return count <= 1;
        
    }
};
// @lc code=end

