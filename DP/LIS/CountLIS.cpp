// problem link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// Most Optimal Approach
// TC : O(N * N)
// SC : O(N)
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> counts(n, 1);
    int mx = 1;
    int ans = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i] && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];
                counts[i] = counts[j];
            }
            else if(nums[j] < nums[i] && 1 + dp[j] == dp[i]) {
                counts[i] += counts[j];
            }
        }

        mx = max(mx, dp[i]);
    }

    for(int i = 0; i < n; i++) {
        if(dp[i] == mx)
            ans += counts[i];
    }
    return ans;
}

// Notes :
/*
# Number of Longest Increasing Subsequences - Complete Solution Notes

## Problem Understanding
We need to find how many different longest increasing subsequences exist in an array. The key insight is that we need to track not just the length of the LIS ending at each position, but also how many different ways we can achieve that length.

## Core Algorithm Approach
The solution uses **dual dynamic programming arrays**:
- `dp[i]`: Length of the longest increasing subsequence ending at position i
- `counts[i]`: Number of different LIS of length `dp[i]` ending at position i

## Step-by-Step Algorithm Breakdown

### Initialization Phase
```cpp
vector<int> dp(n, 1);      // Every single element forms an LIS of length 1
vector<int> counts(n, 1);  // There's exactly 1 way to form each single-element LIS
int mx = 1;                // Track the maximum LIS length found so far
```

**Why start with 1?** Every individual element by itself is a valid increasing subsequence of length 1, and there's exactly one way to form it.

### Main DP Loop Logic
For each position `i`, we examine all previous positions `j < i` to see if we can extend subsequences:

#### Case 1: Found a Longer Subsequence
```cpp
if(nums[j] < nums[i] && 1 + dp[j] > dp[i]) {
    dp[i] = 1 + dp[j];      // Update to the longer length
    counts[i] = counts[j];   // Inherit the count from position j
}
```
**What's happening?** We found a way to make a longer LIS ending at position `i` by extending from position `j`. Since this is strictly better than what we had before, we completely replace our previous count with the count from position `j`.

#### Case 2: Found Another Way to Achieve Same Length
```cpp
else if(nums[j] < nums[i] && 1 + dp[j] == dp[i]) {
    counts[i] += counts[j];  // Add to existing count
}
```
**What's happening?** We found another position `j` that can extend to the same maximum length at position `i`. Since we now have multiple ways to achieve this length, we add the count from position `j` to our existing count.

### Final Counting Phase
```cpp
for(int i = 0; i < n; i++) {
    if(dp[i] == mx)
        ans += counts[i];
}
```
**Why check all positions?** The longest increasing subsequences might end at different positions in the array. We need to sum up all the counts from positions that achieve the maximum length.

## Worked Example: [1,3,5,4,7]

### Initial State
- `dp = [1,1,1,1,1]` (each element forms length-1 LIS)
- `counts = [1,1,1,1,1]` (one way each)

### Processing i=1 (value=3)
- Check j=0: 1 < 3, and 1+1=2 > 1, so update dp[1]=2, counts[1]=1
- Result: `dp=[1,2,1,1,1]`, `counts=[1,1,1,1,1]`

### Processing i=2 (value=5)
- Check j=0: 1 < 5, 1+1=2 > 1, so dp[2]=2, counts[2]=1
- Check j=1: 3 < 5, 1+2=3 > 2, so dp[2]=3, counts[2]=1
- Result: `dp=[1,2,3,1,1]`, `counts=[1,1,1,1,1]`

### Processing i=3 (value=4)
- Check j=0: 1 < 4, 1+1=2 > 1, so dp[3]=2, counts[3]=1
- Check j=1: 3 < 4, 1+2=3 > 2, so dp[3]=3, counts[3]=1
- Check j=2: 5 > 4, skip (can't extend)
- Result: `dp=[1,2,3,3,1]`, `counts=[1,1,1,1,1]`

### Processing i=4 (value=7)
- Check j=0: 1 < 7, 1+1=2 > 1, so dp[4]=2, counts[4]=1
- Check j=1: 3 < 7, 1+2=3 > 2, so dp[4]=3, counts[4]=1
- Check j=2: 5 < 7, 1+3=4 > 3, so dp[4]=4, counts[4]=1
- Check j=3: 4 < 7, 1+3=4 == 4, so counts[4] += 1 = 2
- Result: `dp=[1,2,3,3,4]`, `counts=[1,1,1,1,2]`

### Final Answer
- Maximum length: mx = 4
- Positions with max length: only position 4
- Answer: counts[4] = 2

The two LIS of length 4 are: [1,3,5,7] and [1,3,4,7]

## Key Insights for Memory

**The Two-Array Pattern**: Whenever you need to count the number of ways to achieve an optimal solution in DP, consider using two arrays - one for the optimal value and one for the count.

**The Addition vs Replacement Logic**: When you find a better solution, replace the count. When you find an equally good solution, add to the count.

**Check All Ending Positions**: The optimal solution might end at multiple different positions, so always check all positions in your final counting phase.

## Time and Space Complexity
- **Time Complexity**: O(n²) due to the nested loops
- **Space Complexity**: O(n) for the two DP arrays

## Common Mistakes to Avoid
1. **Forgetting to reset counts**: When you find a longer subsequence, you must replace (not add to) the count
2. **Only checking the last position**: The LIS might end at different positions
3. **Off-by-one errors**: Remember that extending from position j adds 1 to dp[j], not dp[i]

## Testing Strategy
Always test with:
1. Arrays where all elements are the same (answer should be n)
2. Strictly increasing arrays (answer should be 1) 
3. Arrays with multiple LIS ending at different positions
4. Single element arrays (edge case)

This pattern appears in many DP counting problems, so mastering this dual-array approach will serve you well in similar questions!
*/