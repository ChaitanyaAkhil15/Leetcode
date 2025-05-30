// Problem Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// This problem is a variant of Longest Plaindromic Subsequence, If we can find the length of the longest palindromic subsequence
// in the given string (let's say k), we need to insert (n-k) characters to make the string palindromic.
// Optimized Approach
// TC : O(n * m)
// SC : O(m)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }
        
        return prev[m];
    }

    int longestPalindromeSubseq(string s) {
        string reverse = string(s.rbegin(), s.rend());

        return longestCommonSubsequence(s, reverse);
    }

    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};