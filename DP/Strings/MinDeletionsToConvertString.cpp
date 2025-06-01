// Problem Link : https://leetcode.com/problems/delete-operation-for-two-strings/description/
// This problem is a variant of Longest Common Subsequence, If we can find the length of the longest common subsequence
// in the given strings (let's say k), we need to delete (n + m - 2 * k) characters to make the strings equal.

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
    
    int minDistance(string word1, string word2) {
        int len = longestCommonSubsequence(word1, word2);
        int n = word1.length(), m = word2.length();

        return n + m - 2 * len;
    }
};