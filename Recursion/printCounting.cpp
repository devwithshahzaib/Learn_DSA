#include <iostream>
using namespace std;
void printCounting(int n)
{
    if (n == 0)
    {
        return;
    }
    // recursive relation
    printCounting(n - 1); // head recursion
    cout << n << endl;
}
int main()
{
    printCounting(5);
    return 0;
}