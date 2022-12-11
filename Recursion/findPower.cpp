#include <iostream>
using namespace std;

//For Understanding recursion process

// int i = 0;
// long findPower(int number, int pow)
// {
//     i++;
//     cout << "function call " << i << endl;
//     cout << "iteration: " << i << ", pow: " << pow << endl;
//     if (pow == 0)
//     {

//         cout << "\nBase Condition TRUE Returned 1,\nnumber * returnValue(initially 1) = result" << endl;
//         return 1;
//     }

//     int smallerProblem = findPower(number, pow - 1);
//     cout << number << " * " << smallerProblem << "(result)"
//          << " = " << number * smallerProblem << endl;
//     return number * smallerProblem;
// }
long findPower(int number, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    return number * findPower(number, pow - 1);
}

int main()
{
    int num, pow;
    long result;
    cout << "Enter Number and then Power" << endl;
    cin >> num >> pow;
    result = findPower(num, pow);
    cout << num << " raised to power " << pow << " = " << result << endl;
    return 0;
}