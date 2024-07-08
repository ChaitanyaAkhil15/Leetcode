#include<bits/stdc++.h>
using namespace std;

//iterate from the end
//push largest element to the end

int main()
{
    int N = 6;
    vector<int> arr = {13,46,24,52,20,9};

    for(int i = N - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    for(int ele : arr)
        cout << ele << " ";
    cout << "\n";

    return 0;
}