#include <bits/stdc++.h>
using namespace std;

//we use HashMap approach to calculate longest window with sum k if the input contains negative values too 
//as the two pointer approach won't work for this usecase
int findLongestWindow(int arr[], int N, int k)
{
    int right = 0;
    unordered_map<long long int , int> prefixSumMap;
    long long int sum = 0, rem = 0;
    int mx_size = 0;

    while(right < N)
    {
        sum += arr[right];
        
        if(sum == k)
            mx_size = max(mx_size, right + 1);
        
        rem = sum - k;
        if(prefixSumMap.find(rem) != prefixSumMap.end())
            mx_size = max(mx_size, right - prefixSumMap[rem]);
        
        if(prefixSumMap.find(sum) == prefixSumMap.end())
            prefixSumMap[sum] = right;
        right++;
    }

    return mx_size;
}

int main()
{
    int arr[] = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 15;

    cout << findLongestWindow(arr, N, k) << endl;

    return 0;
}