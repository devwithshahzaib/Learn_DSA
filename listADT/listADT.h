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
    virtual void deleteAtIndex(int index) = 0;
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
        cout << "Array of Capapcity " << capacity << " is created.\nDo you want to insert Elements Now?[Y/N]" << endl;
        char response;
        cin >> response;
        if (response == 'Y' || response == 'y')
        {
            cout << "Enter values. Press -1 to stop. MAX(" << capacity << " values)" << endl;

            for (int i = 0; i < capacity; i++)
            {
                int value;
                cin >> value;
                if (value == -1)
                {
                    break;
                }
                else
                {
                    insertAtEnd(value);
                }
            }
            cout << "\nValues Inserted Successfully.\n";
        }
        else
        {
            cout << "\nNo Values Inserted!\n";
        }

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
        if (lastIndex >= capacity - 1)
        {
            cout << "Capacity is full!" << endl;
            return;
        }

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

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > lastIndex)
        {
            cout << "Invalid Index" << endl;
            return;
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
        return;
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
    bool isEmpty()
    {
        if (lastIndex == -1)
        {
            cout << "\nEmpty Status: List is Empty!\n";
            return false;
        }
        return true;
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
        cout << "Enter values in List." << endl;
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
        if (head == NULL)
        {
            cout << "\nList is Empty!\n";
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
        insertAtIndex(listLength + 1, value);
    }
    // index starts from 1 instead of 0
    void insertAtIndex(int nodeIndex, int data)
    {
        Node *currentNode = head, *prevNode = NULL, *newNode;
        newNode = new Node(data);
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
            return;
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
    void deleteAtIndex(int nodeIndex)
    {
        Node *currentNode = head, *prevNode = NULL;

        // Check if the index to be
        // deleted is greater than the length
        // of the link list.
        if (listLength < nodeIndex)
        {
            cout << "Index out of range" << endl;
            return;
        }

        // Deleting the head.
        if (nodeIndex == 1)
        {
            // Update head with next
            head = head->next;
            listLength--;
            return;
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
        int i = 1, foundCount = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "\nKey " << key << ", Found at index " << i << endl;
                foundCount++;
            }
            temp = temp->next;
            i++;
        }
        if (foundCount == 0)
        {
            cout << "\nSorry, query not found." << endl;
        }
        cout << "Found Count: " << foundCount << endl;
    }
    void sort()
    {
        int tempValue;
        Node *current = head, *forwardNode = NULL;

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
    bool isEmpty()
    {
        if (listLength == 0)
        {
            cout << "Empty Status: List is Empty!" << endl;
            return false;
        }
        return true;
    }

    ~LinkList() {}
};