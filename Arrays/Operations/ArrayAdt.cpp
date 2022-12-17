#include <iostream>
using namespace std;

class ArrayAdt
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    ArrayAdt()
    {
        capacity = 0;
        lastIndex = -1;
        ptr = NULL;
    }
    void createArr(int capacity);
    int getItem(int index);
    int setItem(int index, int value);
    int editItem(int index, int value);
    int countItems();
    void deleteItem(int index);
    int searchItem(int value);
    void sortArr();
    void printEle(int index);
    void printList();
    ~ArrayAdt()
    {
        delete[] ptr;
    }
};

void ArrayAdt::createArr(int capacity)
{
    this->capacity = capacity;
    lastIndex = -1;
    ptr = new int[capacity];
}

int ArrayAdt::getItem(int index)
{
    if (lastIndex == -1)
    {
        cout << "\nList is Not Created" << endl;
    }

    if (index > capacity - 1 || index < 0)
    {
        cout << "\nInvalid Index" << endl;
        return (-1);
    }
    return (ptr[index]);
}

int ArrayAdt::setItem(int index, int value)
{
    if (lastIndex == capacity - 1)
        cout << "\nOverflow" << endl;
    else if (index > capacity - 1 || index < 0)
    {
        cout << "\nInvalid Index" << endl;
        return (-1);
    }
    else if (index <= lastIndex)
    {
        int i;
        lastIndex++;
        i = lastIndex;
        while (i != index)
        {
            ptr[i] = ptr[i - 1];
            i--;
        }
        return (ptr[index] = value);
    }
    else if (index == lastIndex + 1)
        lastIndex++;
    ptr[index] = value;
}

int ArrayAdt::editItem(int index, int value)
{
    if (index > lastIndex || index < 0)
    {
        cout << "\nInvalid Index" << endl;
    }
    else
        ptr[index] = value;
}

int ArrayAdt::countItems()
{
    return (lastIndex + 1);
}

void ArrayAdt::deleteItem(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "\nInvalid Index Or Underflow" << endl;
    }
    else if (index < lastIndex)
    {
        int i = index;
        while (i != lastIndex)
        {
            ptr[i] = ptr[i + 1];
            i++;
        }
        lastIndex--;
    }

    else if (index < lastIndex + 1)
        lastIndex--;
}

int ArrayAdt::searchItem(int value)
{
    if (lastIndex == -1)
    {
        cout << "\nList is Not Created" << endl;
    }
    for (int i = 0; i < capacity; i++)
    {
        if (ptr[i] == value)
        {
            cout << "The value " << value << " Exist at index " << i << endl;
            return (i);
        }
    }
    return (-1);
}

void ArrayAdt::sortArr()
{
    int temp;
    for (int i = 0; i < countItems(); i++)
    {
        for (int j = 0; j < countItems() - i; j++)
        {
            if (ptr[i] > ptr[i + 1])
            {
                temp = ptr[i];
                ptr[i] = ptr[i + 1];
                ptr[i + 1] = temp;
            }
        }
    }
}

void ArrayAdt::printEle(int index)
{
    cout << "The Value At Index " << index << " is " << ptr[index] << endl;
}

void ArrayAdt::printList()
{
    int size = lastIndex + 1;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
}

int main()
{
    ArrayAdt l1;
    int size = 7;
    l1.createArr(size);

    // l1.setItem(0,61);
    // l1.setItem(1,62);
    // l1.setItem(2,63);
    // l1.setItem(3,64);
    // l1.setItem(1,48);
    // l1.printEle(1);
    // l1.printEle(4);
    int value;
    for (int i = 0; i < size - 2; i++)
    {
        cout << "Enter Value at Index " << i << ": ";
        cin >> value;
        l1.setItem(i, value);
    }

    // l1.sortArr();
    l1.deleteItem(1);
    l1.deleteItem(2);
    // for (int i = 0; i < size; i++)
    // {
    //     l1.printEle(i);
    //     " ";
    // }
    cout<<l1.countItems();

    return 0;
}