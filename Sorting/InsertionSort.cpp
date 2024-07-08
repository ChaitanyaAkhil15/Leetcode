#include<bits/stdc++.h>

using namespace std;

//Place the element in correct place in sorted array

int main()
{
    int N = 6;
    vector<int> arr = {13,46,24,52,20,9};

    for(int i = 0; i < N; i++)
    {
        for(int j = i; j >= 1; j--)
        {
            if(arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
        
    }

    for(int ele : arr)
        cout << ele << " ";
    cout << "\n";

    return 0;
}