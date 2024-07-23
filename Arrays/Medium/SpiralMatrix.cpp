#include <bits/stdc++.h>
using namespace std;

void SpiralMatrix(vector<vector<int>> &matrix, int n, int m, vector<int> &ans)
{
    int toprow = 0, rightcol = m-1, bottomrow = n-1, leftcol = 0;
    while(toprow <= bottomrow && leftcol <= rightcol)
    {
        for(int i = leftcol; i <= rightcol; i++)
            ans.push_back(matrix[toprow][i]);
        toprow++;

        for(int i = toprow; i <= bottomrow; i++)
            ans.push_back(matrix[i][rightcol]);
        rightcol--;

        if(toprow <= bottomrow)
        {
            for(int i = rightcol; i >= leftcol; i--)
                ans.push_back(matrix[bottomrow][i]);
            bottomrow--;

            for(int i = bottomrow; i >= toprow; i--)
                ans.push_back(matrix[i][leftcol]);
            leftcol++;
        }
        
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int n = 3, m = 4;
    vector<int> ans;

    SpiralMatrix(matrix, n, m, ans);
    
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}