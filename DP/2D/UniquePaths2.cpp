// Problem link: https://leetcode.com/problems/unique-paths-ii/description/

// Recursive Approach
// Time Complexity : O(2^(m + n))
// Space Complexity : O(m + n)

class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& obstacleGrid) {
            if(i == 0 && j == 0) return 1;
    
            if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;
    
            int up = solve(i - 1, j, obstacleGrid);
            int left = solve(i, j - 1, obstacleGrid);
    
            return up + left;
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            if(obstacleGrid[0][0] == 1) return 0;
            
            return solve(m - 1, n - 1, obstacleGrid);
        }
    };

// ------------------------------------------------------------------------->

// Memoization Approach 
// Time Complexity : O(m * n)
// Space Complexity : O(m * n) + O(m + n) Stack Space => O(m * n)

class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
            if(i == 0 && j == 0) return 1;
    
            if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;
    
            if(dp[i][j] != 0) return dp[i][j];
    
            int up = solve(i - 1, j, dp, obstacleGrid);
            int left = solve(i, j - 1, dp, obstacleGrid);
    
            return dp[i][j] = up + left;
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            if(obstacleGrid[0][0] == 1) return 0;
    
            return solve(m - 1, n - 1, dp, obstacleGrid);
        }
    };

// ------------------------------------------------------------------------->

// Tabular Approach 
// Time Complexity : O(m * n)
// Space Complexity : O(m * n) => O(m * n)

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
    
            if(obstacleGrid[0][0] == 1) return 0;
    
            dp[0][0] = 1;
    
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) continue;
    
                    if(obstacleGrid[i][j] == 1) continue;
    
                    if(i - 1 >= 0) dp[i][j] += dp[i - 1][j];
                    if(j - 1 >= 0) dp[i][j] += dp[i][j - 1];
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
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<int> prev(n, 0);
    
            if(obstacleGrid[0][0] == 1) return 0;
    
            for(int i = 0; i < m; i++) {
                vector<int> curr(n, 0);
    
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) {
                        curr[j] = 1;
                        continue;
                    }
    
                    if(obstacleGrid[i][j] == 1) continue;
    
                    if(i - 1 >= 0) curr[j] += prev[j];
                    if(j - 1 >= 0) curr[j] += curr[j - 1];
                }
    
                prev = curr;
            }
    
            return prev[n - 1];
        }
    };