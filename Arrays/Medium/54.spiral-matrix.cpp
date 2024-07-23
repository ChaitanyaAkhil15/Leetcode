/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (50.39%)
 * Likes:    14783
 * Dislikes: 1308
 * Total Accepted:    1.5M
 * Total Submissions: 3M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int toprow = 0, rightcol = m-1, bottomrow = n-1, leftcol = 0;

        while(toprow <= bottomrow && leftcol <= rightcol)
        {
            for(int i = leftcol; i <= rightcol; i++)
                ans.push_back(matrix[toprow][i]);
            toprow++;

            for(int i = toprow; i <= bottomrow; i++)
                ans.push_back(matrix[i][rightcol]);
            rightcol--;

            if(toprow <= bottomrow)
            {
                for(int i = rightcol; i >= leftcol; i--)
                    ans.push_back(matrix[bottomrow][i]);
                bottomrow--;
            }

            if(leftcol <= rightcol)
            {
                for(int i = bottomrow; i >= toprow; i--)
                    ans.push_back(matrix[i][leftcol]);
                leftcol++;
            } 
        }

        return ans;
    }
};
// @lc code=end

