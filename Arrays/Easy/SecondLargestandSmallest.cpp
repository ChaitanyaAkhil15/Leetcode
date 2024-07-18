#include <bits/stdc++.h>
using namespace std;


int second_largest(vector<int> &arr, int n)
{
    int first_largest = INT_MIN;
    int second_largest = INT_MIN;


    for(int i = 0; i < n; i++)
    {
        if(arr[i] > first_largest)
        {
            second_largest = first_largest;
            first_largest = arr[i];
        }
        else
        {
            if(arr[i] > second_largest && arr[i] != first_largest)
                second_largest = arr[i];
        }
    }
    
    return second_largest;
}


int second_smallest(vector<int> &arr, int n)
{
    int first_smallest = INT_MAX;
    int second_smallest = INT_MAX;


    for(int i = 0; i < n; i++)
    {
        if(arr[i] < first_smallest)
        {
            second_smallest = first_smallest;
            first_smallest = arr[i];
        }
        else
        {
            if(arr[i] < second_smallest && arr[i] != first_smallest)
                second_smallest = arr[i];
        }
    }
    
    return second_smallest;
}

int main()
{
    vector<int> arr = {1, 8, 7, 56, 90};
    int n = arr.size();

    int largest = second_largest(arr, n);
    int smallest = second_smallest(arr, n);

    cout << largest << " " << smallest << "\n";
}