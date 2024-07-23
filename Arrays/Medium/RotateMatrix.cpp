#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();

    for(int i = 0; i < n; i++)
    {
        for
    }



    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

void transposeInPlace(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < m; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // rotate(matrix);
    transposeInPlace(matrix);
    return 0;
}