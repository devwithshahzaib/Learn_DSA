#include <iostream>
#include<conio.h>
using namespace std;
int changeNo(int number)
{
    int n;
    cout << "Enter no to change with: ";
    cin >> n;
    number = n;
}
void changeNo(int *number)
{
    int n;
    cout << "Enter no to change with: ";
    cin >> n;
    *number = n;
}
int main()
{
    int x = 9;

    // call by value
    cout << "Call by Value" << endl;
    cout << "The Previous No: " << x << endl;
    changeNo(x);
    cout << "The Current No: " << x << endl;

    getch();

    // call by refrence
    cout << "----------------\nCall by Refrence" << endl;
    cout << "The Previous No: " << x << endl;
    changeNo(&x);
    cout << "The Current No: " << x << endl;
    
    return 0;
}