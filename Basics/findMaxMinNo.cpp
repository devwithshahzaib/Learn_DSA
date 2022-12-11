#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    int minNo = INT_MAX;
    int maxNo = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxNo)
        {
            maxNo = arr[i];
        }
        if (arr[i] < minNo)
        {
            minNo = arr[i];
        }
    }
    cout<<"Min No: "<<minNo<<"\nMax No: "<<maxNo;
    return 0;
}