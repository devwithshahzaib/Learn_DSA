#include <iostream>
using namespace std;
class Stack
{
    int top, size;
    int *arr;

public:
    Stack()
    {
        size = -1;
        arr = NULL;
        top = -1;
    }
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack is full\n";
        }
        else
        {
            top++;
            arr[top] = data;
            cout << "Pushed " << data << " into STACK | pos:" << top << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            cout << "Popped " << arr[top] << " from STACK | pos:" << top << endl;
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            cout << "\nStack is: ";
            for (int i = 0; i <= top; i++)
            {

                cout << arr[i] << " ";
            }
            cout << endl<<endl;
        }
    }
};
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    s.pop();
    s.pop();
    s.display();
    return 0;
}