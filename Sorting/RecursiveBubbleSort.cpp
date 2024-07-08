#include<bits/stdc++.h>
using namespace std;

//iterate from the end
//push largest element to the end

void bubble_sort(vector<int> &arr, int i, int N)
{
    if(i == -1)
        return;
    
    int start = 0, end = i;
    while(start < i)
    {
        if(arr[start] > arr[start + 1])
            swap(arr[start], arr[start + 1]);
        start++;
    }

    bubble_sort(arr, i - 1, N);
}

int main()
{
    int N = 6;
    vector<int> arr = {13,46,24,52,20,9};

    bubble_sort(arr, N-1, N);

    for(int ele : arr)
        cout << ele << " ";
    cout << "\n";

    return 0;
}