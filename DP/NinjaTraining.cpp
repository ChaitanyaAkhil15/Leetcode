// Problem link : https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM
// Top-Down Approach
// Time Complexity : O(N * 4 * 3) => O(N)
// Space Complexity : O(N * 4) + O(N) Stack Space => O(N)
int solve(vector<vector<int>>& points, vector<vector<int>>& dp, int day, int last) {
    if(day == 0) {
        int mx = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                mx = max(mx, points[day][task]);
            }
        }

        return mx;
    }

    if(dp[day][last] != 0)
        return dp[day][last];
        
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + solve(points, dp, day - 1, task);
            dp[day][last] = max(dp[day][last], point);
        }
    }

    return dp[day][last];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    return solve(points, dp, n - 1, 3);
}


// ---------------------------------------------------------------------------------------------------------------->


// Bottom-Up Approach
// Time Complexity : O(N * 4 * 3) => O(N)
// Space Complexity : O(N * 4) => O(N)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    for(int task = 0; task < 3; task++) {
        dp[0][task] = points[0][task];
    }

    dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2]));

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    dp[day][last] = max(dp[day][last], points[day][task] + dp[day-1][task]);
                }
            }
        }
    }

    // Reason why dp[n-1][3] stores the answer
    // The reason this works is that dp[day][3] is designed to store the global maximum merit points up to day, 
    // regardless of the activity performed on the previous day.
    // dp[day][3] always contains the best possible score for the current day, considering all valid activity sequences up to that point.
    return dp[n-1][3];
}


// ------------------------------------------------------------------------------------------------------------------------------------------------->
// Bottom-Up Approach Space Optimized (Space Reduction)
// Time Complexity : O(N * 4 * 3) => O(N)
// Space Complexity : O(4 + 4) => O(1)

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, 0);
    
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++) {
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        dp = temp;
    }

    return dp[3];
}
