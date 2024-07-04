#include <iostream>
using namespace std;


int printSum(int N)
{
    if(N == 0)
        return 0;
    return N + printSum(N-1);
}


int main()
{
    int N = 5;
    int result = printSum(N);
    cout << result << endl;
}