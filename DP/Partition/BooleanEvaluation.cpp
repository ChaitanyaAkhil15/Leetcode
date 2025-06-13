// problem link : https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM

// Memoization Approach
// TC : O(N * N * 2 * N) = O(N ^ 3)
// SC : O(N * N * 2) = O(N  ^ 2)
#include <bits/stdc++.h>
int mod = 1e9 + 7;

int solve(int i, int j, int isTrue, string& exp, vector<vector<vector<int>>>& dp) {
    if(i > j)
        return 0;
    
    if(i == j) {
        if(isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    
    int TotalWays = 0;
    for(int ind = i + 1; ind <= j - 1; ind+= 2) {
        // We need to check the number of ways we can make left partition True or False
        // And right partition True or False;
        // lT represents ways to make left partition true
        long long int lT = solve(i, ind - 1, 1, exp, dp);
        long long int lF = solve(i, ind - 1, 0, exp, dp);
        long long int rT = solve(ind + 1, j, 1, exp, dp);
        long long int rF = solve(ind + 1, j, 0, exp, dp);

        if(exp[ind] == '&'){
            if(isTrue)
                TotalWays = (TotalWays + (lT * rT) % mod) % mod;
            else
                TotalWays = (TotalWays + (lF * rF) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
        }
        else if(exp[ind] == '|') {
            if(isTrue)
                TotalWays = (TotalWays + (lT * rT) % mod + (lT * rF) % mod
                            + (lF * rT) % mod) % mod;
            else
                TotalWays = (TotalWays + (lF * rF) % mod) % mod;
        }
        else {
            // for XOR we know T^T and F^F will evaluate to F
            if(isTrue)
                TotalWays = (TotalWays + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else
                TotalWays = (TotalWays + (lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }

    return dp[i][j][isTrue] = TotalWays;
}

int evaluateExp(string & exp) {
    int n = exp.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(0, n - 1, 1, exp, dp);
}

// Tabulation Approach
#include <bits/stdc++.h>
int mod = 1e9 + 7;

int evaluateExp(string & exp) {
    int n = exp.length();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

    for(int i = 0; i < n; i+=2) {
        if(exp[i] == 'T')
            dp[i][i][1] = 1;
        else
            dp[i][i][0] = 1; 
    }

    // since we are computing at indices where i and j are operands
    // we can skip the operators by i -= 2 and j += 2
    // And since we've evaluated for i == j already, we don't have to compute it again
    // so we can start j from next operand after i -> j = i + 2
    // and we can also skip computation when i == j
    for(int i = n - 1; i >= 0; i -= 2) {
        for(int j = i + 2; j <= n; j += 2) {
            if(i == j) continue;
            
            for(int isTrue = 0; isTrue <= 1; isTrue++) {
                int TotalWays = 0;
                for(int ind = i + 1; ind <= j - 1; ind+= 2) {
                    // We need to check the number of ways we can make left partition True or False
                    // And right partition True or False;
                    // lT represents ways to make left partition true
                    long long int lT = dp[i][ind - 1][1];
                    long long int lF = dp[i][ind - 1][0];
                    long long int rT = dp[ind + 1][j][1];
                    long long int rF = dp[ind + 1][j][0];

                    if(exp[ind] == '&'){
                        if(isTrue)
                            TotalWays = (TotalWays + (lT * rT) % mod) % mod;
                        else
                            TotalWays = (TotalWays + (lF * rF) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                    }
                    else if(exp[ind] == '|') {
                        if(isTrue)
                            TotalWays = (TotalWays + (lT * rT) % mod + (lT * rF) % mod
                                        + (lF * rT) % mod) % mod;
                        else
                            TotalWays = (TotalWays + (lF * rF) % mod) % mod;
                    }
                    else {
                        // for XOR we know T^T and F^F will evaluate to F
                        if(isTrue)
                            TotalWays = (TotalWays + (lT * rF) % mod + (lF * rT) % mod) % mod;
                        else
                            TotalWays = (TotalWays + (lT * rT) % mod + (lF * rF) % mod) % mod;
                    }
                }

                dp[i][j][isTrue] = TotalWays;
            }
        }
    }

    return dp[0][n - 1][1];
}

