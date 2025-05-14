// Problem Link : https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885

// Recursive Approach
// TC : O(3^r * 3^r)
// SC : O(r)
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid) {
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e6;

    if(i == r-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    
    int mx = INT_MIN;
    for(int dj1 = -1; dj1 < 2; dj1++) {
        for(int dj2 = -1; dj2 < 2; dj2++) {
            int value = 0;
            if(j1 == j2) value = grid[i][j1] + solve(i + 1, dj1 + j1, dj2 + j2, r, c, grid);
            else value = grid[i][j1] + grid[i][j2] + solve(i + 1, dj1 + j1, dj2 + j2, r, c, grid);
            mx = max(mx, value);
        }
    }

    return mx;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return solve(0, 0, c - 1, r, c, grid);
}

// -------------------------------------------------------------------------------------------------------------------->

// Memoization Approach
// TC : O(r * c * c) * 9
// SC : O(r * c * c) + O(r)
int solve(int i, int j1, int j2, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<int>> &grid) {
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e6;

    if(i == r-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int mx = INT_MIN;
    for(int dj1 = -1; dj1 < 2; dj1++) {
        for(int dj2 = -1; dj2 < 2; dj2++) {
            int value = 0;
            if(j1 == j2) value = grid[i][j1] + solve(i + 1, dj1 + j1, dj2 + j2, r, c, dp, grid);
            else value = grid[i][j1] + grid[i][j2] + solve(i + 1, dj1 + j1, dj2 + j2, r, c, dp, grid);
            mx = max(mx, value);
        }
    }

    return dp[i][j1][j2] = mx;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return solve(0, 0, c - 1, r, c, dp, grid);
}

// -------------------------------------------------------------------------------------------------------------------->


// Tabular Approach
// TC : O(r * c * c) * 9
// SC : O(r * c * c)
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2)
                dp[r-1][j1][j2] = grid[r-1][j1];
            else
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i = r - 2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                int mx = INT_MIN;

                for(int dj1 = -1; dj1 < 2; dj1++) {
                    for(int dj2 = -1; dj2 < 2; dj2++) {
                        int newj1 = j1 + dj1;
                        int newj2 = j2 + dj2;

                        if(newj1 >= 0 && newj1 < c && newj2 >= 0 && newj2 < c)
                            mx = max(mx, dp[i + 1][newj1][newj2]);
                    }
                }

                if(j1 == j2)
                    dp[i][j1][j2] = grid[i][j1] + mx;
                else
                    dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + mx;
            }
        }
    }

    return dp[0][0][c-1];
}

// -------------------------------------------------------------------------------------------------------------------->

// Tabular Approach Space Optimized
// TC : O(r * c * c) * 9
// SC : O(c * c)
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> next(c, vector<int>(c, -1));

    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2)
                next[j1][j2] = grid[r-1][j1];
            else
                next[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i = r - 2; i >= 0; i--) {
        vector<vector<int>> curr(c, vector<int>(c, -1));

        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                int mx = -1e6;

                for(int dj1 = -1; dj1 < 2; dj1++) {
                    for(int dj2 = -1; dj2 < 2; dj2++) {
                        int newj1 = j1 + dj1;
                        int newj2 = j2 + dj2;

                        if(newj1 >= 0 && newj1 < c && newj2 >= 0 && newj2 < c)
                            mx = max(mx, next[newj1][newj2]);
                    }
                }

                if(j1 == j2)
                    curr[j1][j2] = grid[i][j1] + mx;
                else
                    curr[j1][j2] = grid[i][j1] + grid[i][j2] + mx;
                
            }
        }
        
        next = curr;
    }

    return next[0][c-1];
}