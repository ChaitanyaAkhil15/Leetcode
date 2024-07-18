#include <bits/stdc++.h>
using namespace std;


int largest(vector<int> &arr, int n)
{
    int ele = INT_MIN;

    for(int i = 0; i < n; i++)
        ele = max(arr[i], ele);
    
    return ele;
}

int main()
{
    vector<int> arr = {1, 8, 7, 56, 90};
    int n = arr.size();

    int ans = largest(arr, n);

    cout << n << "\n";
}