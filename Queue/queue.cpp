#include <iostream>
using namespace std;
class Queue
{
    int front, rear, size;
    int *arr;

public:
    Queue()
    {
        size = -1;
        arr = NULL;
        front = -1;
        rear = -1;
    }
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full\n";
        }
        else
        {
            rear++;
            arr[rear] = data;
            cout << "Enqueued " << data << " into QUEUE | pos:" << rear << endl;
        }
    }
    void dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else
        {
            cout << "Dequeued " << arr[front] << " from QUEUE | pos:" << front << endl;
            front++;
        }
    }
    void display()
    {
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else
        {
            cout << "\nQueue is: ";
            for (int i = front + 1; i <= rear; i++)
            {

                cout << arr[i] << " ";
            }
            cout << endl
                 << endl;
        }
    }
};
int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}
