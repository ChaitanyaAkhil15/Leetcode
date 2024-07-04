#include <iostream>
#include<vector>
using namespace std;


int Factorial(int N)
{
    if(N == 1)
        return 1;
    return N * Factorial(N - 1);
}


int main()
{
    int N = 5;
    auto result = Factorial(N);
    cout << result << "\n";
}