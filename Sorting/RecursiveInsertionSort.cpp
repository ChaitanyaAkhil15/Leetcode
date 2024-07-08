#include<bits/stdc++.h>

using namespace std;

//Place the element in correct place in sorted array

void insertion_sort(vector<int> &arr, int i, int N)
{

    if(i == N)
        return;
        
    int ind = i;
    while(ind > 0)
    {
        if(arr[ind] < arr[ind-1])
            swap(arr[ind], arr[ind-1]);
        
        ind--;
    }
    insertion_sort(arr, i + 1, N);
}

int main()
{
    int N = 6;
    vector<int> arr = {13,46,24,52,20,9};

    insertion_sort(arr, 0, N);

    for(int ele : arr)
        cout << ele << " ";
    cout << "\n";

    return 0;
}