#include <iostream>
using namespace std;
class array
{
    int *arrayPtr;
    int lastIndex;
    int capacity;

public:
    array()
    {
        arrayPtr = NULL;
        lastIndex = -1;
        capacity = 0;
    }
    void printArray()
    {
        int size = lastIndex + 1;
        for (int i = 0; i < size; i++)
        {
            cout << arrayPtr[i] << " ";
        }
        cout << endl;
    }
    void createArray(int capacity)
    {
        this->arrayPtr = new int[capacity];
        this->capacity = capacity;
        this->lastIndex = -1;
        for (int i = 0; i < capacity; i++)
        {
            arrayPtr[i] = -1;
        }
    }
    void insertAtEnd(int value)
    {
        lastIndex++;
        arrayPtr[lastIndex] = value;
    }
    void sort()
    {
        int count = 0;
        while (count < lastIndex)
        {
            for (int i = 0; i < lastIndex - count; i++)
            {
                if (arrayPtr[i] > arrayPtr[i + 1])
                {
                    swap(arrayPtr[i], arrayPtr[i + 1]);
                }
            }
            count++;
        }
    }
    void search(int key)
    {
        int foundCount = 0;
        for (int i = 0; i < lastIndex + 1; i++)
        {
            if (key == arrayPtr[i])
            {
                cout << "Key found at index: " << i << endl;
                foundCount++;
            }
        }
        cout << "Found Count: " << foundCount << endl;
    }
    void getCount()
    {
        cout << "Count Items: " << lastIndex + 1 << endl;
    }
    void insertAtFront(int value)
    {
        insertAtIndex(value, 0);
    }
    void deleteAtFront()
    {
        deleteAtIndex(0);
    }
    void deleteAtEnd()
    {
        deleteAtIndex(lastIndex);
    }
    void deleteAtIndex(int index)
    {
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid Index" << endl;
        }
        else if (index < lastIndex)
        {
            int i = index;
            while (i != lastIndex)
            {
                arrayPtr[i] = arrayPtr[i + 1];
                i++;
            }
            lastIndex--;
        }
        else if (index < lastIndex + 1)
            lastIndex--;
    }
    void insertAtIndex(int value, int index)
    {
        int i;

        // increase the size by 1
        lastIndex++;
        if (index >= lastIndex)
        {
            if (index == lastIndex)
            {
                lastIndex--; // decrement increased size
                insertAtEnd(value);
                return;
            }
            else
            {
                cout << "OverFlow, Invalid Index!" << endl;
                lastIndex--; // decrement increased size
                return;
            }
        }

        // shift elements forward
        for (i = lastIndex; i >= index; i--)
        {

            arrayPtr[i] = arrayPtr[i - 1];
        }

        // insert x at pos
        arrayPtr[index] = value;
    }

    void printSize()
    {
        cout << capacity;
    }
    ~array() {}
};
int main()
{
    array a;
    a.createArray(10);
    a.insertAtEnd(1);
    a.insertAtEnd(2);
    a.insertAtEnd(3);
    a.insertAtEnd(4);
    a.insertAtEnd(5);
    cout << "\nArray: ";
    a.printArray();
    cout << "\n-------------\n";
    cout << "\nSearching Item... key 5\n";
    a.search(5);
    cout << "\n-------------\n";
    cout << "\nInsert key 99 at index 3 \n";
    a.insertAtIndex(99, 3);
    a.getCount();

    cout << "New Array: ";
    a.printArray();
    cout << "\n-------------\n";
    cout << "\nInserting key 11 at Front...\n";
    a.insertAtFront(11);
    a.getCount();
    cout << "New Array: ";
    a.printArray();
    cout << "\n-------------\n";
    cout << "\nDeleting Item From Front...\n";
    a.deleteAtFront();
    a.getCount();
    cout << "New Array: ";
    a.printArray();
    cout << "\n-------------\n";
    cout << "\nSorting Array...\n";
    a.sort();
    cout << "New Sorted Array: ";
    a.printArray();
    cout << "\n-------------\n";
    return 0;
}