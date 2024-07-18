#include <bits/stdc++.h>
using namespace std;


vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    int left1 = 0, right1 = n-1, left2 = 0, right2 = m-1;
    vector<int> ans;

    while(left1 <= right1 && left2 <= right2)
    {
        if(arr1[left1] <= arr2[left2])
        {
            if(ans.size() == 0)
                ans.push_back(arr1[left1]);
            else
            {
                if(ans[ans.size() - 1] != arr1[left1])
                    ans.push_back(arr1[left1]);
            }
            left1++;
        }
        else
        {
            if(ans.size() == 0)
                ans.push_back(arr2[left2]);
            else
            {
                if(ans[ans.size() - 1] != arr2[left2])
                    ans.push_back(arr2[left2]);
            }
            left2++;
        }

    }

    while(left1 <= right1)
    {
        if(ans[ans.size() - 1] != arr1[left1])
            ans.push_back(arr1[left1]);
        left1++;
    }
    
    while(left2 <= right2)
    {
        if(ans[ans.size() - 1] != arr2[left2])
            ans.push_back(arr2[left2]);
        left2++;
    }
    
    return ans;
}

int main()
{
    int n = 2, arr1[] = {-7, 8};  
    int m = 3, arr2 [] = {-8, -3, 8};

    vector<int> ans = findUnion(arr1, arr2, n, m);

    for(auto ele : ans)
        cout << ele << " ";
    cout << "\n";

    return 0;
}