// problem link : https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Most Optimal Solution
// TC : O(2N) For loop and Stack operations
// SC : O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        int n = heights.size();
        int maxArea = -1;

        for(int i = 0; i < n; i++)
        {
            while(!stack.empty() && heights[stack.top()] > heights[i])
            {
                int nse = i;
                int curr_height = stack.top();
                stack.pop();
                int pse = (stack.empty()) ? -1 : stack.top();
                maxArea = max(maxArea, heights[curr_height] * (nse - pse - 1));
            }
            stack.push(i);
        }

        while(!stack.empty())
        {
            int nse = n;
            int curr_height = stack.top();
            stack.pop();
            int pse = (stack.empty()) ? -1 : stack.top();

            maxArea = max(maxArea, heights[curr_height] * (nse - pse - 1));
        }

        return maxArea;
    }
};