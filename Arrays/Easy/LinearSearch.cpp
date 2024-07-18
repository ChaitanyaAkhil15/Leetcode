#include <bits/stdc++.h>
using namespace std;

int searchInSorted(int arr[], int N, int K) 
    { 
        int ans = -1;
    
       for(int i = 0; i < N; i++)
       {
           if(arr[i] > K)
            break;
           if(arr[i] == K)
            {
                ans = 1;
                break;
            }
       }
       
       return ans;
       
}

int main()
{
    int N = 5, K = 6;
    int arr[] = {1, 2, 3, 4, 6};

    cout << searchInSorted(arr, N, K) << endl;
    return 0;
}