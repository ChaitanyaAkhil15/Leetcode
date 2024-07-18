#include <bits/stdc++.h>
using namespace std;

//reverse specific range within an array
void reverse_array(int arr[], int left, int right)
{
    while(left < right)
        swap(arr[left++], arr[right--]);
}

int main()
{
    int N = 6, K = 2;
    int arr[] = {1,2,3,4,5,6};
    // 6 5 4 3 2 1
    // 3 4 5 6 1 2
    int left = 0, right = N - 1;
    
    //reverse the entire array
    reverse_array(arr, 0, N-1);

    //reverse the first N-K elements
    reverse_array(arr, 0, N-K-1);

    //reverse the last K elements
    reverse_array(arr, N-K, N-1);

    for(int ele : arr)
        cout << ele << " ";
    cout << "\n";

    
    return 0;
}