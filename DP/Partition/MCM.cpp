// problem link : https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344?leftPanelTabValue=PROBLEM

// Memoization Approach
// TC : O(N ^ 3)
// SC : O(N ^ 2) + O(N) recursion stack space
#include <bits/stdc++.h> 

int solve(int i, int j, vector<int> &arr, vector<vector<int>>& dp) {
    if(i == j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int mn = 1e9;
    for(int k = i; k < j; k++) {
        int operations = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        mn = min(mn, operations);
    }

    return dp[i][j] = mn;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(1, N-1, arr, dp);
}

// Tabular Approach
// TC : O(N ^ 3)
// SC : O(N ^ 2)
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for(int i = N - 1; i >= 1; i--) {
        for(int j = i + 1; j < N; j++) {
            int mn = 1e9;
            for(int k = i; k < j; k++) {
                int operations = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mn = min(mn, operations);
            }

            dp[i][j] = mn;
        }
    }
    
    return dp[1][N - 1];
}