#include <iostream>
using namespace std;

class listADT
{
public:
    virtual bool create(int capacity) = 0;
    virtual void insertAtFront(int value) = 0;
    virtual void insertAtEnd(int value) = 0;
    virtual void insertAtIndex(int index, int value) = 0;
    virtual void deleteAtFront() = 0;
    virtual void deleteAtEnd() = 0;
    virtual bool deleteAtIndex(int index) = 0;
    virtual void search(int key) = 0;
    virtual void print() = 0;
    virtual void sort() = 0;
    virtual int getLength() = 0;
};

class arrayList : public listADT
{
    int *arrayPtr;
    int lastIndex;
    int capacity;

public:
    arrayList()
    {
        arrayPtr = NULL;
        lastIndex = -1;
        capacity = 0;
    }
    bool create(int capacity)
    {
        this->arrayPtr = new int[capacity];
        this->capacity = capacity;
        this->lastIndex = -1;
        for (int i = 0; i < capacity; i++)
        {
            arrayPtr[i] = -1;
        }
        cout << "Array of Capapcity " << capacity << " is created." << endl;
        return true;
    }
    void insertAtFront(int value)
    {
        insertAtIndex(0, value);
    }
    void insertAtEnd(int value)
    {
        lastIndex++;
        arrayPtr[lastIndex] = value;
    }
    void insertAtIndex(int index, int value)
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
    void deleteAtFront()
    {
        deleteAtIndex(0);
    }
    void deleteAtEnd()
    {
        deleteAtIndex(lastIndex);
    }

    bool deleteAtIndex(int index)
    {
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid Index" << endl;
            return false;
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
        return true;
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
        if (foundCount == 0)
        {
            cout << "Sorry, Query not found." << endl;
        }
        cout << "Found Count: " << foundCount << endl;
    }
    void print()
    {
        int size = lastIndex + 1;
        for (int i = 0; i < size; i++)
        {
            cout << arrayPtr[i] << " ";
        }
        cout << endl;
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
    int getLength()
    {
        return lastIndex + 1;
    }
    ~arrayList() {}
};

// node class
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {}
};
class LinkList : public listADT
{
private:
    Node *head;
    int listLength;

public:
    LinkList()
    {
        head = NULL;
        listLength = 0;
    }
    void insertNode(int data)
    {
        // create a new node
        Node *newNode;
        // allocated dynamic memory to node and insert data
        newNode = new Node(data);

        // check if list is empty
        if (head == NULL)
        {
            head = newNode;
            listLength++;
            return;
        }

        // create temporary node and assign the head
        Node *temp = head;

        // traverse temp till end of list i.e next == NULL
        while (temp->next != NULL)
        {
            // update next
            temp = temp->next;
        }
        // insert node at the end
        temp->next = newNode;
        listLength++;
    }
    bool create(int capacity)
    {
        int input;
        cout << "Enter values in List. MAX(" << capacity << " values) " << endl;
        while (capacity != 0)
        {
            cin >> input;
            insertNode(input);
            capacity--;
        }
        return true;
    }
    void print()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertAtFront(int value)
    {
        insertAtIndex(1, value);
    }
    void insertAtEnd(int value)
    {
        insertAtIndex(listLength, value);
    }
    // index starts from 1 instead of 0
    void insertAtIndex(int nodeIndex, int value)
    {
        Node *currentNode = head, *prevNode = NULL, *newNode;
        newNode = new Node(value);
        if (nodeIndex < 0)
        {
            cout << "\nInvalid Index\n";
            return;
        }
        if (nodeIndex == 1)
        {
            newNode->next = head;
            head = newNode;
            listLength++;
        }

        while (nodeIndex > 1)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
            nodeIndex--;
        }
        prevNode->next = newNode;
        newNode->next = currentNode;
        listLength++;
    }
    bool deleteAtIndex(int nodeIndex)
    {
        Node *currentNode = head, *prevNode = NULL;

        // Check if list is Empty
        if (isEmpty())
        {
            return false;
        }
        // Check if the index to be
        // deleted is greater than the length
        // of the link list.
        if (listLength < nodeIndex)
        {
            cout << "Index out of range" << endl;
            return false;
        }

        // Deleting the head.
        if (nodeIndex == 1)
        {
            // Update head with next
            head = head->next;
            listLength--;
            return true;
        }

        // Traverse the list to
        // find the node to be deleted.
        while (nodeIndex > 1) // loop continue until it finds the nodeIndex
        {
            // Update previous node
            prevNode = currentNode;
            // Update curent node
            currentNode = currentNode->next;
            nodeIndex--;
        }

        // Change the next pointer
        // of the previous node.
        prevNode->next = currentNode->next;
        listLength--;
        // Delete the node
        delete currentNode;
    }
    void deleteAtFront()
    {
        deleteAtIndex(1);
    }
    void deleteAtEnd()
    {
        deleteAtIndex(listLength);
    }
    int getLength()
    {
        return listLength;
    }
    void search(int key)
    {
        Node *temp = head;
        int i = 1, count = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Key " << key << ", Found at index " << i << endl;
                count++;
            }
            temp = temp->next;
            i++;
        }
        if (count == 0)
        {
            cout << "Sorry, query not found." << endl;
        }
    }
    void sort()
    {
        int tempValue;
        Node *current = head, *forwardNode = NULL;
        if (isEmpty())
        {
            return;
        }
        else
        {
            while (current != NULL)
            {
                // index points to the node next to current
                forwardNode = current->next;

                while (forwardNode != NULL)
                {
                    if (current->data > forwardNode->data)
                    {
                        // swap first with second
                        tempValue = current->data;
                        current->data = forwardNode->data;
                        forwardNode->data = tempValue;
                    }
                    forwardNode = forwardNode->next;
                }
                current = current->next;
            }
        }
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return true;
        }
        else
            return false;
    }

    ~LinkList() {}
};
int main()
{
    // list->create(10);

    // list->print();
    // list->search(3);

    // link->create(5);
    // // link->print();
    // // cout << endl;
    // // cout << link->getLength();
    // // cout << endl;
    // // link->deleteAtEnd();
    // link->print();
    // // link->deleteAtIndex(3);
    // link->sort();
    // link->print();
    // link->search(4);
    listADT *list;
    int listType, selectedOperation;
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
    default:
        break;
    }
    cout << "\nFollowing Operations are availabe in LIST ADT Data Structure:" << endl;
    while (!exitProgram)
    {
        cout << "\n---------------------------------------|\n\n";
        cout << "1. Insert Element at front" << endl;
        cout << "2. Insert Element at last" << endl;
        cout << "3. Insert Element at index" << endl;
        cout << "4. Remove Element at front" << endl;
        cout << "6. Remove Element at last" << endl;
        cout << "7. Remove Element at index" << endl;
        cout << "8. Find Element" << endl;
        cout << "9. Print List" << endl;
        cout << "10. Sort List" << endl;
        cout << "99. Exit" << endl;
        cout << "\n---------------------------------------|\n";
        cout << "\nSelect Operation...";
        cin >> selectedOperation;
        switch (selectedOperation)
        {
        case 99:
            exitProgram = true;
            break;

        default:
            break;
        }
    }

    return 0;
}