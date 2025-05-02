// Problem link: https://leetcode.com/problems/unique-paths-ii/description/

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
        int solve(int i, int j, vector<vector<int>>& grid) {
            if(i == 0 && j == 0) return grid[0][0];
    
            if(i < 0 || j < 0) return INT_MAX;
            
            int up = solve(i - 1, j, grid);
            int left = solve(i, j - 1, grid);
    
            return min(up, left) + grid[i][j];
        }
    
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            
            return solve(m - 1, n - 1, grid);
        }
    };

// ------------------------------------------------------------------------->

// Memoization Approach 
// Time Complexity : O(m * n)
// Space Complexity : O(m * n) + O(m + n) Stack Space => O(m * n)

class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
            if(i == 0 && j == 0) return grid[0][0];
    
            if(i < 0 || j < 0) return INT_MAX;
            
            if(dp[i][j] != 0) return dp[i][j];
    
            int up = solve(i - 1, j, dp, grid);
            int left = solve(i, j - 1, dp, grid);
    
            return dp[i][j] = min(up, left) + grid[i][j];
        }
    
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            return solve(m - 1, n - 1, dp, grid);
        }
    };

// ------------------------------------------------------------------------->

// Tabular Approach 
// Time Complexity : O(m * n)
// Space Complexity : O(m * n) => O(m * n)

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            dp[0][0] = grid[0][0];
    
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) continue;
    
                    int up = INT_MAX, left = INT_MAX;
                    if(i - 1 >= 0) up = dp[i - 1][j];
                    if(j - 1 >= 0) left = dp[i][j - 1];
    
                    dp[i][j] = min(up, left) + grid[i][j];
                }
            }
    
            return dp[m - 1][n - 1];    
        }
    };

// ------------------------------------------------------------------------->

// Tabular Approach with Space Reduction
// Time Complexity : O(m * n)
// Space Complexity : O(n) => O(n)

// Note: We can use a single array of size n instead of a 2D array.
// we can always do this because we only need the previous row to calculate the current row.
// i.e, the parameters are only changing by 1 (next recursion call will always be i - 1 or j - 1).
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> prev(n, 0);
    
            for(int i = 0; i < m; i++) {
                vector<int> curr(n, 0);
    
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) {
                        curr[j] = grid[0][0];
                        continue;
                    }
    
                    int up = INT_MAX, left = INT_MAX;
                    if(i - 1 >= 0) up = prev[j];
                    if(j - 1 >= 0) left = curr[j - 1];
    
                    curr[j] = min(up, left) + grid[i][j];
                }
    
                prev = curr;
            }
    
            return prev[n - 1];    
        }
    };