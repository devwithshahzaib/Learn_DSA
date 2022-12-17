#include <iostream>
using namespace std;
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current, j;
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
int main()
{
    int size = 5;
    int arr[size] = {4, 3, 8, 3, 2};
    insertionSort(arr, size);
    printArray(arr,size);
    return 0;
}