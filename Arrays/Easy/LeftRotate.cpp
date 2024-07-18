#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 5;
    int arr[] = {1,2,3,4,5};
    
    int temp = arr[0];
    for(int i = 0; i < N - 1; i++)
        arr[i] = arr[i + 1];
    
    arr[N - 1] = temp;

    for(int ele : arr)
    {
        cout << ele << " ";
    }
    cout << "\n";
    
    return 0;
}