// Print LIS

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);           // dp[i] = length of LIS ending at index i
    vector<int> hash(n);            // hash[i] = previous index in LIS ending at i
    int mx = 1, lastIndex = 0;      // Track maximum length and its ending index

    // Initialize hash array - each element initially points to itself
    for(int i = 0; i < n; i++) {
        hash[i] = i;
    }

    // Fill the DP table
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            // If we can extend the LIS ending at j by including nums[i]
            if(nums[j] < nums[i] && 1 + dp[j] > dp[i]) {
                dp[i] = 1 + dp[j];  // Update the length
                hash[i] = j;        // Remember that j comes before i in LIS
            }
        }
        
        // After processing all previous elements for position i,
        // check if this gives us a new maximum
        if(dp[i] > mx) {
            mx = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruct the LIS by tracing back through hash array
    vector<int> lis;
    int current = lastIndex;
    
    // Trace back until we reach an element that points to itself
    while(hash[current] != current) {
        lis.push_back(nums[current]);
        current = hash[current];
    }
    // Don't forget to add the first element of the LIS
    lis.push_back(nums[current]);
    
    // Reverse to get the correct order (we built it backwards)
    reverse(lis.begin(), lis.end());
    
    // Print the LIS
    cout << "Longest Increasing Subsequence: ";
    for(int i = 0; i < lis.size(); i++) {
        cout << lis[i];
        if(i < lis.size() - 1) cout << " ";
    }
    cout << endl;
    
    return mx;
}