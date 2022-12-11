#include <iostream>
using namespace std;
int fabonaciiNthTerm(int n)
{
    if (n < 1)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int ans = fabonaciiNthTerm(n - 1) + fabonaciiNthTerm(n - 2);
    return ans;
}
int main()
{
    int n;
    cout << "Enter nth term, you want to find of Fibonacii series" << endl;
    cin >> n;
    cout << "The " << n << "th term of fibonacii series is: " << fabonaciiNthTerm(n)<<endl;
    
    //print series
    int i = 0;
    while (i <= n)
    {
        cout << fabonaciiNthTerm(i) << " ";
        i++;
    }
    return 0;
}