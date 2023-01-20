#include "listADT.h"
#include <iostream>
using namespace std;

int main()
{
    listADT *list;
    int listType, selectedOperation, capacity, value, index;
    bool mainMenu = true, exitProgram = false;

    cout << "Which ADT do you want to run?" << endl;
    cout << "1: Array List\n2: Link List" << endl;
    cin >> listType;
    switch (listType)
    {
    case 1:
        list = new arrayList();
        break;
    case 2:
        list = new LinkList();
        break;
    default:
        cout << "\nPlease select from given statement!\n";
        break;
    }
    cout << "\nCreate list of capacity?: ";
    cin >> capacity;
    list->create(capacity);
    cout << "\nFollowing Operations are availabe in LIST ADT Data Structure:" << endl;
    while (!exitProgram)
    {
        cout << "\n---------------------------------------|\n\n";
        cout << "1. Insert Element at front" << endl;
        cout << "2. Insert Element at last" << endl;
        cout << "3. Insert Element at index" << endl;
        cout << "4. Remove Element at front" << endl;
        cout << "5. Remove Element at last" << endl;
        cout << "6. Remove Element at index" << endl;
        cout << "7. Find Element" << endl;
        cout << "8. Print List" << endl;
        cout << "9. Sort List" << endl;
        cout << "10. Get List Length" << endl;
        cout << "11. Check if List is Empty" << endl;
        cout << "99. Exit" << endl;
        cout << "\n---------------------------------------|\n";
        cout << "\nSelect Operation...";
        cin >> selectedOperation;
        switch (selectedOperation)
        {
        case 1:
            cout << "\nEnter Value You Want To Insert: ";
            cin >> value;
            list->insertAtFront(value);

            break;
        case 2:
            cout << "\nEnter Value You Want To Insert: ";
            cin >> value;
            list->insertAtEnd(value);

            break;
        case 3:
            cout << "\nEnter value and Index No. in which you want to Insert: ";
            cin >> value >> index;
            list->insertAtIndex(index, value);

            break;
        case 4:
            list->deleteAtFront();
            break;
        case 5:
            list->deleteAtEnd();
            break;
        case 6:
            cout << "\nEnter index No. you want to remove: ";
            cin >> index;
            list->deleteAtIndex(index);
            break;
        case 7:
            cout << "\nEnter value you want to find: ";
            cin >> value;
            cout << "\nSearching for element " << value << "...";
            list->search(value);
            break;
        case 8:
            cout << "\nPrint Status: ";
            list->print();
            break;
        case 9:
            list->sort();
            cout << "\nList Sorted: ";
            list->print();
            break;
        case 10:
            cout << "\nLength Status: " << list->getLength() << endl;
            break;
        case 99:
            exitProgram = true;
            break;

        default:
            cout << "\nPlease Select from the given operations.\n";
            continue;
        }
    }

    return 0;
}