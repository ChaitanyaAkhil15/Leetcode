// Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/

// Recursion Approach
// TC : O(3^(n))
// SC : O(n * n) + O(n) Stack Space => O(n * n)
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int n) {
        if(j < 0 || j >= n) return 1e6;

        if(i == 0) return matrix[i][j];

        int top = matrix[i][j] + solve(matrix, i - 1, j, n);
        int top_left = matrix[i][j] + solve(matrix, i - 1, j - 1, n);
        int top_right = matrix[i][j] + solve(matrix, i - 1, j + 1, n);

        return min(top, min(top_left, top_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mn = INT_MAX;

        for(int j = 0; j < n; j++) {
            mn = min(mn, solve(matrix, n - 1, j, n));
        }

        return mn;
    }
};

// ------------------------------------------------------------------------->
// Memoization Approach
// TC : O(n * n)
// SC : O(n * n) + O(n) Stack Space => O(n * n) 
class Solution {
public:
    class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n) {
        if(j < 0 || j >= n) return 1e6;

        if(i == 0) return matrix[i][j];

        if(dp[i][j] != 1e6) return dp[i][j];
        
        int top = matrix[i][j] + solve(matrix, dp, i - 1, j, n);
        int top_left = matrix[i][j] + solve(matrix, dp, i - 1, j - 1, n);
        int top_right = matrix[i][j] + solve(matrix, dp, i - 1, j + 1, n);

        return dp[i][j] = min(top, min(top_left, top_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mn = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 1e6));

        for(int j = 0; j < n; j++) {
            mn = min(mn, solve(matrix, dp, n - 1, j, n));
        }

        return mn;
    }
};
};

// Tabular Approach
// TC : O(n * n)
// SC : O(n * n)
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mn = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Build the DP table row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({up, left, right});
            }
        }

        for(int j = 0; j  < n; j++) {
            mn = min(mn, dp[n - 1][j]);
        }

        return mn;
}

// Tabular Approach with Space Optimization
// TC : O(n * n)
// SC : O(n)
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev(matrix[0]); // Initialize with the first row

    for (int i = 1; i < n; i++) {
        vector<int> curr(n, INT_MAX);
        for (int j = 0; j < n; j++) {
            int up = prev[j];
            int left = (j > 0) ? prev[j - 1] : INT_MAX;
            int right = (j < n - 1) ? prev[j + 1] : INT_MAX;
            curr[j] = matrix[i][j] + min({up, left, right});
        }
        prev = curr;
    }

    // Find the minimum value in the last row
    return *min_element(prev.begin(), prev.end());
}