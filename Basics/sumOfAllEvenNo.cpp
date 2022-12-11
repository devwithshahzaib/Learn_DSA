#include <iostream>
using namespace std;

int main()
{
    int number;
    int sum = 0;
    cout<<"Enter no. ";
    cin>>number;
    for (int i = 1; i <= number; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + i;
        }
    }
    cout << "Sum of EVEN No\'s in " << number << " is " << sum << endl; 
    sum = 0;
    for (int i = 1; i <= number; i++)
    {
        if (i % 2 != 0)
        {
            sum = sum + i;
        }
    }
    cout << "Sum of ODD No\'s in " << number << " is " << sum << endl; 

    return 0;
}