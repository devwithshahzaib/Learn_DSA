#include <iostream>
using namespace std;
void swap(int *toBeSwaped, int *swapWith)
{
    int temp;
    temp = *swapWith;
    *swapWith = *toBeSwaped;
    *toBeSwaped = temp;
}
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
void swapAlternate(int arr[], int length)
{
    for (int i = 0; i < length; i += 2)
    {
        if (i + 1 < length)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
int main()
{
    int arr[] = {1, 2, 4, 5, 6};
    printArray(arr, 5);
    cout << endl;
    swapAlternate(arr, 5);
    printArray(arr, 5);
    return 0;
}