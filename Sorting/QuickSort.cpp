#include<bits/stdc++.h>
using namespace std;

int partition_index(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while(i <= high - 1 && arr[i] <= pivot)
            i++;

        while(j >= low + 1 && arr[j] > pivot)
            j--;
        
        if(i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition_index(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int N = 7;
    int arr[] = {3,2,8,5,1,4,23};

    quick_sort(arr, 0, N-1);

    for(int ele : arr)
        cout << ele << " ";
    cout << "\n";

    return 0;
}