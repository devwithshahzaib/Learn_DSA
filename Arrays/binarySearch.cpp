#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Key found at index " << mid << endl;
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "Couldn't find key" << endl;
    return -1;
}
int main()
{
    int size = 5;
    int key = 3;
    int array[size] = {3, 5, 6, 7, 8};
    cout<<binarySearch(array, size, key);

    return 0;
}