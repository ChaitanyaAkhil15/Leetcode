// problem link : https://leetcode.com/problems/maximal-rectangle/

// This problem is an extension of Largest Rectangle Area in Histogram
// In this problem we see what is the maximum area reactangle we can form for the given row(& rows above) and in the end
// see what is the max area in total that can be formed

// Optimized Approach
// TC : O(n * m)
// SC : O(n * m)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        int n = heights.size();
        int maxArea = 0;

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        int maxArea = 0;

        for(int j = 0; j < m; j++)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                if(matrix[i][j] == '1')
                    sum += 1;
                else if(matrix[i][j] == '0')
                    sum = 0;

                prefixSum[i][j] = sum;
            }
        }

        for(int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
        }

        return maxArea;
    }
};