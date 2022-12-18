#include <iostream>
using namespace std;
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
class LinkList
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
    void createList()
    {
        int input;
        cout << " Enter Data in List. [Press -1 to Exit...]" << endl;
        while (true)
        {
            cin >> input;
            if (input == -1)
            {
                break;
            }
            insertNode(input);
        }
    }
    void printList()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;
        // cout << "Head Address: " << temp << endl<<"----------------"<<endl;
        while (temp != NULL)
        {
            // cout << "own address: " << temp << endl
            //      << "data: " << temp->data << endl
            //      << "next address: " << temp->next << endl<<"----------------"<<endl;
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
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
    bool deleteNode(int nodeIndex)
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
    int getListLength()
    {
        return listLength;
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
    LinkList link;
    link.createList();
    link.printList();
    cout << "Length: " << link.getListLength() << endl;
    link.insertAtIndex(3, 1122);
    link.printList();
    cout << "Length: " << link.getListLength() << endl;
    link.deleteNode(4);
    link.printList();
    cout << "Length: " << link.getListLength() << endl;

    return 0;
}
