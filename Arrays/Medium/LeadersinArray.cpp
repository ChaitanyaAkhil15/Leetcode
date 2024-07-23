// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

#include <bits/stdc++.h>
using namespace std;
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> ans;
        
        int max = arr[n - 1];
        ans.push_back(arr[n - 1]);
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] >= max)
            {
                max = arr[i];
                ans.insert(ans.begin(), arr[i]);
            }
        }
        
        // reverse(ans.begin(), ans.end());  
        return ans;
    }
};