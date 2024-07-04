#include <iostream>
using namespace std;


void printName(string name, int N)
{
    if(N == 0)
        return;
    cout << name << " ";
    printName(name, N-1);
}


int main()
{
    string name = "Recursion";
    int N = 5;
    printName(name, N);
    cout << "\n";
}