#include<iostream>
using namespace std;

void ReverseArray(int *arr, int start, int end)
{
    if(start < end)
    {
        swap(arr[start], arr[end]);
        ReverseArray(arr, start + 1, end - 1);
    }
}

void PrintArray(int *arr, int N)
{
    for(int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int N = 5;
    int arr[] = {5, 4, 3, 2, 1};
    int start = 0, end = N - 1;
    ReverseArray(arr, start, end);
    PrintArray(arr, N);
    return 0;
}