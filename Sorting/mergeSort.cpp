#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;

    int left = low, right = mid + 1;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while(left <= mid)
        temp.push_back(arr[left++]);

    while(right <= high)
        temp.push_back(arr[right++]);

    for(int i = low; i <= high; i++)
        arr[i] = temp[i-low];   //temp has merged elements from index 0 whereas arr[] should be filled from low -> high
    
}


void merge_sort(int arr[], int low, int high)
{
    if(low >= high)
        return;
     
    int mid = (low + high) / 2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int N = 5;
    int arr[] = {4,2,1,6,7};
    
    merge_sort(arr, 0, N - 1);

    for(int ele : arr)
        cout << ele << "\n";
    cout << "\n";

    return 0;
}