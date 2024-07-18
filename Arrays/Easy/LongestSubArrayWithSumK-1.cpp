#include <bits/stdc++.h>
using namespace std;

//This is the two pointer approach and it would only work for positive elements
//There is two different ways to implement it
//you can keep increasing the right pointer in the while loop
//or you could keep increasing the left pointer
int longestSubarrayWithSumK(int arr[], long long k) {
    int left = 0, right = 0, mx_sz = 0;
    long long int sum = 0;
    int N = sizeof(arr) / sizeof(arr[0]);

    while(right < N)
    {
        while(right < N && sum <= k)
        {
            sum += arr[right];
            if(sum == k)
                mx_sz = max(mx_sz, right - left + 1);
            right++;
        }
        sum -= arr[left++];
        if(sum == k)
            mx_sz = max(mx_sz, right - left);

    }
    return mx_sz;
}

int longestSubarrayWithSumK_better(vector<int> arr, long long k) {
    int left = 0, right = 0, mx_sz = 0;
    long long int sum = 0;
    int N = arr.size();

    while(right < N)
    {
        sum += arr[right];
        
        while(sum > k)
            sum -= arr[left++];
        
        if(sum == k)
            mx_sz = max(mx_sz, right-left+1);
        
        right++;
    }
    return mx_sz;
}

int main()
{
    int arr[] = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 15;

    cout << longestSubarrayWithSumK(arr, k) << endl;

    return 0;
}