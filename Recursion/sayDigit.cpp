#include <iostream>
using namespace std;
void sayDigit(int number, string arrOfDigits[])
{
    if (number == 0)
    {
        return;
    }
    int digit = number % 10; // gives the last digit i.e 432 % 10 = 2
    number = number / 10;    // updates the number by removing last digit, to one step back i.e 432 / 10 = 43, in cpp '/', operator truncates the decimal points.
    sayDigit(number, arrOfDigits);
    cout << arrOfDigits[digit] << " ";
}
int main()
{
    string digits[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int n;
    cout << "Enter Number: ";
    cin >> n;
    sayDigit(n, digits);
    return 0;
}