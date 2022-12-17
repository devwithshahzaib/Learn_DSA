#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            cout << "Key found at index " << i << endl;
            return i;
        }
    }
    cout<<"Couldn't find key"<<endl;
}
int main()
{
    int size = 5;
    int key = 8;
    int array[size] = {3, 5, 6, 7, 8};
    linearSearch(array, size, key);

    return 0;
}