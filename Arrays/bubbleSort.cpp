#include <iostream>
using namespace std;
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
void bubleSort(int arr[], int size)
{
    int count = 0;
    while (count < size - 1)
    {
        // cout << count << "count" << endl;

        for (int i = 0; i < size - count; i++)
        {
            // printArray(arr, size);
            // cout<<endl;
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        count++;
    }
}

int main()
{
    int arr[] = {2, 9, 4, 7, 5, 1, 3};
    printArray(arr, 7);
    bubleSort(arr, 7);
    cout << endl;
    printArray(arr, 7);
    return 0;
}