#include<bits/stdc++.h>

using namespace std;

//select the minimum element and place it in beginning

int main()
{
    int N = 6;
    vector<int> arr = {13,46,24,52,20,9};

    for(int i = 0; i < N; i++)
    {
        int min_element = arr[i];
        int ind = i;

        for(int j = i + 1; j < N; j++)
        {
            if(arr[j] < min_element)
            {
                ind = j;
                min_element = arr[j];
            }
        }
        
        swap(arr[i], arr[ind]);
    }

    for(int ele : arr)
        cout << ele << " ";
    cout << "\n";

    return 0;
}