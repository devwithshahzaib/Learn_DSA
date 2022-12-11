#include <iostream>
using namespace std;

int main()
{
    int num;
    bool isPrime = true;
    cout << "Please Enter a Number to Check Wether its Prime Or not" << endl;
    cin >> num;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            isPrime = false;
        }
    }
    if (isPrime == true)
    {
        cout << "The Number " << num << " is "
             << "Prime Number";
    }
    else
        cout << "The Number " << num << " is Not "
             << "Prime Number";

    return 0;
}