#include <iostream>
using namespace std;
template <class X>
class stack
{
private:
    int top;
    X *ptr;
    int capacity;
public:
    stack() {}
    stack(int);
    void push(X);
    X pop();
    void display();
    X peek();
    bool isEmpty();
    bool isFull();
    ~stack();
};
template <class X>
stack<X>::~stack()
{
    delete[] ptr;
}

template <class X>
bool stack<X>::isEmpty()
{
    return top == -1;
}
template <class X>
bool stack<X>::isFull()
{
    return top == capacity - 1;
}

template <class X>
X stack<X>::peek()
{
    return ptr[top];
}

template <class X>
void stack<X>::display()
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i <= top; i++)
            cout << ptr[i] << " ";
    }
}

template <class X>
X stack<X>::pop()
{
    if (top == -1)
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    X x;
    x = ptr[top];
    top--;
    return x;
}

template <class X>
void stack<X>::push(X data)
{
    if (top == capacity - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top++;
        ptr[top] = data;
    }
}

template <class X>
stack<X>::stack(int cap)
{
    capacity = cap;
    top = -1;
    ptr = new X[capacity];
}