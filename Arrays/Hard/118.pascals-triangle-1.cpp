/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (74.90%)
 * Likes:    12863
 * Dislikes: 450
 * Total Accepted:    1.7M
 * Total Submissions: 2.3M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numRows <= 30
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> generateRow(int n)
    {
        vector<int> row;
        long long ans = 1;
        row.push_back(1);

        for(int col = 1; col < n; col++)
        {
            ans = ans * (n - col);
            ans = ans / col;
            row.push_back(ans);
        }

        return row;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++)
        {
            vector<int> row = generateRow(i);
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end

