// problem : https://leetcode.com/problems/minimum-cost-to-cut-a-stick

// Memoization Solution
// TC : O(N * N * N) = O(N ^ 3)
// SC : O(N * N) + O(N) stack space
class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
            
        int min_cost = INT_MAX;
        for(int ind = i; ind <= j; ind++) {
            // To determine the length of each cut portion
            // let's consider the cuts array to be with 0 and n inserted [0, 1, 3, 4, 5, 7] i = 1 & j = 4
            // if a cut happens at ind = 3 we know the cost would be cuts[j + 1] - cuts[i - 1]
            // After the cut we solve for i = 1 && j = 2 [0, 1, 3, 4]
            // Now if we observe, 4 represents where the last cut was made(right end of the cut stick)
            // This way at every portion we know cuts[j+1] represents the right end of the cut stick
            // and cuts[i-1] denotes the left end of the cut stick and subtracting them would give
            // the length of the current stick we are dealing with
            int cost = cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp);
            min_cost = min(min_cost, cost);
        }

        return dp[i][j] = min_cost;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return solve(1, c, cuts, dp);
    }
};

// Tabulation Approach
// TC : O(N ^ 3)
// SC : O(N ^ 2)
// In Memoization we are taking dp of size c + 1, because there will never be a point where we try to access c + 1 
// because of the base case check. Whereas in Tabulation, we do dp[ind + 1] where ind can be c, so we declare a dp of size c + 2
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        for(int i = c; i >= 1; i--) {
            for(int j = i; j <= c; j++) {
                int min_cost = INT_MAX;
                for(int ind = i; ind <= j; ind++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    min_cost = min(min_cost, cost);
                }

                dp[i][j] = min_cost;
            }
        }
        return dp[1][c];
    }
};