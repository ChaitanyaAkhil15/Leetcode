// problem link : https://leetcode.com/problems/palindrome-partitioning-ii/description/

// Memoization
// TC : O(N * N * N) = O(N ^ 3)
// SC : O(N) + O(N) recursion stack space
class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        if(i == j)
            return true;
        
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int solve(int i, int n, string& s, vector<int>& dp) {
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
            
        int minCuts = INT_MAX;
        for(int j = i; j < n; j++) {
            if(isPalindrome(s, i, j)) {
                int cuts = 1 + solve(j + 1, n, s, dp);
                minCuts = min(minCuts, cuts);
            }
        }

        return dp[i] = minCuts;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);

        return solve(0, n, s, dp) - 1;
    }
};

// Tabulation
// TC : O(N * N * N) = O(N ^ 3)
// SC : O(N)
class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        if(i == j)
            return true;
        
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;
            for(int j = i; j < n; j++) {
                if(isPalindrome(s, i, j)) {
                    int cuts = 1 + dp[j + 1];
                    minCuts = min(minCuts, cuts);
                }
            }

            dp[i] = minCuts;
        }

        return dp[0] - 1;
    }
};

// Optimal Approach
// We can Precompute if a substring i..j is Palindrome or not for all values of i and j
// This will reduce the TC to O(N ^ 2)

// TC : O(N ^ 2 + N ^ 2) = O(N ^ 2)
// SC : O(N ^ 2 + N) = O(N ^ 2)
class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        if(i == j)
            return true;
        
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        // Precomputing if a substring i....j is Palindrome or not
        vector<vector<int>> palindrome(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isPalindrome(s, i, j))
                    palindrome[i][j] = 1;
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            int minCuts = INT_MAX;
            for(int j = i; j < n; j++) {
                if(palindrome[i][j]) {
                    int cuts = 1 + dp[j + 1];
                    minCuts = min(minCuts, cuts);
                }
            }

            dp[i] = minCuts;
        }

        return dp[0] - 1;
    }
};