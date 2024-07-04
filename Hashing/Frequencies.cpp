// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

// Finding frequency of elements in the array using memory in-place operations
// Elements in the array are in the range 1 to P
// Ignore elements greater than N

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 2, 3, 5};
    int N = arr.size();
    int P = 5;

    int i = 0;
    while(i < N)
    {
        // If element is already processed (< 0) or if the element is greater than P or N we move forward
        if(arr[i] <= 0 || arr[i] > P || arr[i] > N)
        {
            i++;
            continue;
        }

        //Calculating the index (where the frequency of the element at arr[i] should be stored)
        int ind = arr[i] - 1;

        if(arr[ind] > 0)
        {
            arr[i] = arr[ind];
            arr[ind] = -1;
        }

        else
        {
            arr[ind]--;
            arr[i] = 0;
            i++;
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(arr[i] < 0)
            arr[i] = -arr[i];
        else
            arr[i] = 0;         // Elements greater than N must have a frequency of 0
    }
    
    for(int i : arr)
        cout << i << " ";
    cout << "\n";
   
    return 0;
}