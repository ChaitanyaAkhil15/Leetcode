// Problem Link : https://www.naukri.com/code360/problems/coin-change-finite-supply_2545103

//## Brief Explanation:

// **Manual Reduction Problem:**
// ```cpp
// freq[ind]--;                    // State changes here
// dp[ind][amount] = result;       // Cache result for this state
// freq[ind]++;                    // State changes back
// ```

// - DP assumes `dp[ind][amount]` always represents the **same problem state**
// - But `freq` array changes during recursion, so the **same `(ind, amount)` pair** can represent **different actual states**
// - When DP returns cached result, it uses the wrong answer for the current `freq` state

// **Loop Approach Works:**
// ```cpp
// for(int count = 0; count <= freq[ind]; count++) {
//     // Try all possibilities without changing freq array
//     ways += solve(ind-1, coins, freq, remaining_amount);
// }
// ```

// - `freq` array **never changes** during recursion
// - Each `(ind, amount)` pair always represents the **exact same state**
// - DP memoization works correctly because state is consistent

// **Key Insight:**
// Manual reduction + DP = **Inconsistent state caching**
// Loop approach + DP = **Consistent state caching**

// The loop essentially does the same work as multiple manual reductions, but without breaking the DP invariant.

// Memoization Approach
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int solve(int ind, vector<int>& coins, vector<int>& freq, vector<vector<int>>& dp, int amount) {
    // Base case: if amount is 0, there's exactly 1 way (select no coins)
    if(amount == 0) {
        return 1;
    }
    
    // Base case: if we've processed all coins and amount > 0
    if(ind < 0) {
        return 0;
    }
    
    if(dp[ind][amount] != -1) {
        return dp[ind][amount];
    }
    
    int ways = 0;
    
    // Try using 0 to freq[ind] coins of current denomination
    for(int count = 0; count <= freq[ind]; count++) {
        int remaining = amount - count * coins[ind];
        
        if(remaining >= 0) {
            ways = (ways + solve(ind - 1, coins, freq, dp, remaining)) % MOD;
        } else {
            break; // No point trying higher counts
        }
    }
    
    return dp[ind][amount] = ways;
}

int coinChange(int n, vector<int> &coins, vector<int> &freq, int v) {
    vector<vector<int>> dp(n, vector<int>(v + 1, -1));
    return solve(n - 1, coins, freq, dp, v);
}
