#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Please Enter a Number to Check Wether its Even Or Odd" << endl;
    cin >> num;

   
   
        if (num % 2 == 0)
        {
             cout << "The Number " << num << " is "
             << "Even Number";
        }
    else
        cout << "The Number " << num << " is "
             << "Odd Number";

    return 0;
}