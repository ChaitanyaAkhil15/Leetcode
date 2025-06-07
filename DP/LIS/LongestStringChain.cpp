// problem link : https://leetcode.com/problems/longest-string-chain/

// This is also a variant of LIS, where strings differ by 1 character
// Most Optimal Approach
static bool comp(const string& s1, const string& s2) {
        return s1.length() < s2.length();
    }

bool isPredecessor(string& s1, string&s2) {
    if(s1.size() != s2.size() + 1)
        return false;
    
    int i = 0, j = 0;
    while(i < s1.size()) {
        if(j < s2.size() && s1[i] == s2[j]) {
            i++;
            j++;
        }
        else {
            i++;
        }
    }

    if(i == s1.size() && j == s2.size())
        return true;

    return false;
}

int longestStrChain(vector<string>& words) {
    int n = words.size();
    vector<int> dp(n, 1);
    int mx = 1;

    sort(words.begin(), words.end(), comp);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(isPredecessor(words[i], words[j]) && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
            }
        }
        mx = max(mx, dp[i]);
    }

    return mx;
}