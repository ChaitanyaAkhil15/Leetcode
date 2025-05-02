// Problem link: https://leetcode.com/problems/triangle/

// Recursive Approach
// Time Complexity : O(2^(m + n))
// Space Complexity : O(m + n)

// In this problem, when we go out of bounds, we return INT_MAX.
// This is because we want to find the minimum path sum, and if we go out of bounds,
// we want to ignore that path.
// So, we return INT_MAX to indicate that this path is not valid.
// And when INT_MAX is added, it might exceed the integer range, and at any time either up or left will be INT_MAX.
// So, we can safely find the minimum of up and left and add the current cell value to it.
// This will ensure that we are not considering the out-of-bounds path.
class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& triangle) {
            if(i == 0 && j == 0) return triangle[i][j];
            
            // The condition j > i ensures that j is within bounds, as the valid indices for any given row i are from 0 to i.
            // If j is less than 0 or greater than i, it means we are out of bounds for that row.
            if(j < 0 || j > i) return INT_MAX;
            
            int top = solve(i - 1, j, triangle);
            int top_left = solve(i - 1, j - 1, triangle);
    
            return min(top, top_left) + triangle[i][j];
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            int n = triangle[m - 1].size();
            
            int mn = INT_MAX;
            for(int j = 0; j < n; j++) {
                mn = min(mn, solve(m - 1, j, triangle));
            }
    
            return mn;
        }
    };

// ------------------------------------------------------------------------->

// Memoization Approach 
// Time Complexity : O(m * m)
// Space Complexity : O(m * m) + O(m + m) Stack Space => O(m * m)

class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle) {
            if(i == 0 && j == 0) return triangle[i][j];
            
            // The condition j > i ensures that j is within bounds, as the valid indices for any given row i are from 0 to i.
            // If j is less than 0 or greater than i, it means we are out of bounds for that row.
            if(j < 0 || j  > i) return INT_MAX;
            
            if(dp[i][j] != INT_MAX) return dp[i][j];
    
            int top = solve(i - 1, j, dp, triangle);
            int top_left = solve(i - 1, j - 1, dp, triangle);
    
            return dp[i][j] = min(top, top_left) + triangle[i][j];
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            int n = triangle[m - 1].size();
            vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    
            int mn = INT_MAX;
            for(int j = 0; j < n; j++) {
                mn = min(mn, solve(m - 1, j, dp, triangle));
            }
    
            return mn;
        }
    };

// ------------------------------------------------------------------------->

// Tabular Approach 
// Time Complexity : O(m * m) => O(m^2)
// Space Complexity : O(m * m) => O(m^2)
// Here in the end we have to iterate through the last row of the dp array to find the minimum path sum.
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
    
            dp[0][0] = triangle[0][0];
            
            for(int i = 1; i < m; i++) {
                for(int j = 0; j < triangle[i].size(); j++) {
                    // The condition j < i ensures that j is within bounds, For the row i - 1, the valid column indices are from 0 to i - 1.
                    if(j < i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                    if(j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
    
                    dp[i][j] += triangle[i][j];
                }
            }
            
            // STL function can also be used to find min in a vector *min_element(prev.begin(), prev.end())
            int mn = INT_MAX;
            for(int j = 0; j < n; j++) {
                mn = min(mn, dp[m - 1][j]);
            }
    
            return mn;
        }
    };

// ------------------------------------------------------------------------->

// Tabular Approach with Space Reduction
// Time Complexity : O(m * m) => O(m^2)
// Space Complexity : O(m) => O(m)

// Note: We can use a single array of size n instead of a 2D array.
// we can always do this because we only need the previous row to calculate the current row.
// i.e, the parameters are only changing by 1 (next recursion call will always be i - 1 or j - 1).

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            int n = triangle[m - 1].size();
            vector<int> prev(m, INT_MAX);
    
            for(int i = 0; i < m; i++) {
                // curr is initialized with size i + 1 because any given row i of the triangle will have i + 1 elements.
                vector<int> curr(i + 1, INT_MAX);
    
                for(int j = 0; j < triangle[i].size(); j++) {
                    if(i == 0 && j == 0) {
                        curr[0] = triangle[i][j];
                        continue;
                    }
    
                    if(j < i) curr[j] = min(curr[j], prev[j]);
                    if(j - 1 >= 0) curr[j] = min(curr[j], prev[j - 1]);
    
                    curr[j] += triangle[i][j];
                }
    
                prev = curr;
            }
    
            return *min_element(prev.begin(), prev.end());
        }
    };