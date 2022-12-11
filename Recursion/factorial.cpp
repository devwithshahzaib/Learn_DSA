#include <iostream>
using namespace std;

// Understanding Recursion

// long fact(long n, int i)
// {
//     i++;
//     cout << "Called " << i << " Times, n = " << n << endl;
//     if (n == 0)
//     {
//         return 1;
//     }
//     if (n == 1)
//     {
//         cout << "\nBase condition True, i = " << i << ", n = " << n << endl;
//         return n;
//     }
//     else
//         cout << " " << n << " * "
//              << "fact(" << n - 1 << ")" << endl;
//     return n * fact(n - 1, i);
// }

long fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int main()
{
    long n;
    cout << "Enter the number of which you want the factorial: " << endl;
    cin >> n;
    cout << "Factorial is equal to: " << fact(n);
    return 0;
}