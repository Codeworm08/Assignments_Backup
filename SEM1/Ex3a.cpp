#include <iostream>
using namespace std;
#define SIZE 100

class Height
{
    int ft, in;

public:
    Height()
    {
        ft = 0;
        in = 0;
    }
    Height(int a, int b)
    {
        ft = a;
        in = b;
    }
    void set(int f, int i)
    {
        ft = f;
        in = i;
    }
    bool operator<(Height h)
    {
        int h1 = (ft * 12) + in;
        int h2 = (h.ft * 12) + h.in;
        if (h1 < h2)
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &os, Height h);
};

ostream &operator<<(ostream &os, Height h)
{
    os << h.ft << "ft " << h.in << "in";
    return os;
}

template <class T>
class Stack
{
protected:
    T st[SIZE];
    int top;

public:
    Stack() { top = 0; }
    void display();
    void display(int p);
    void push(T p);
    T pop();
    void peek();
    bool isEmpty()
    {
        if (!top)
            return true;
        else
            return false;
    }
};

template <class T>
void Stack<T>::display()
{
    if (!top)
    {
        cout << "Stack empty!" << endl;
        return;
    }
    for (int i = top - 1; i > 0; i--)
        cout << st[i] << "->";
    cout << st[0];
}

template <class T>
void Stack<T>::display(int p)
{
    if (p >= 0 && p < top)
        cout << "\nElement at depth " << p << ": " << st[top - 1 - p] << endl;
    else
        cout << "Depth " << p << " does not exist in stack." << endl;
}

template <class T>
void Stack<T>::push(T p)
{
    if (top == SIZE)
    {
        cout << "Stack Overflow!" << endl;
        return;
    }
    st[top] = p;
    top++;
}

template <class T>
T Stack<T>::pop()
{
        cout << "Element popped: " << st[top - 1] << endl;
        T p = st[top - 1];
        top--;
        return p;
}

template <class T>
void Stack<T>::peek()
{
    if (top)
        cout << st[top] << endl;
    else
        cout << "Stack empty!" << endl;
}

template <class T>
class Special : public Stack<T>
{
    using Stack<T>::top;
    using Stack<T>::st;
    using Stack<T>::push;

public:
    int mpush(T p);
    void bpush(T p);
};

template <class T>
int Special<T>::mpush(T p)
{
    if ((top == 0 )|| p < st[top-1])
    {
        push(p);
        return 1;
    }
    return 0;
}

template <class T>
void Special<T>::bpush(T p){ this->push(p); }

int main()
{
    Special<Height> s, s1, s2;
    Height h, x;
    int ft, in, ch;
    do
    {
        cout << "\nEnter height in ft and in: ";
        cin >> ft >> in;
        h.set(ft, in);
        s.bpush(h);
        cout << "Stop?0 to stop. 1 continue.." << endl;
        cin >> ch;
    } while (ch);
    cout << "Original Stack:" << endl;
    s.display();
    while (true)
    {
        if (s.isEmpty())
            break;
        x = s.pop();
        if (!s1.mpush(x))
        {
            s2.bpush(x);
            s.bpush(s1.pop());
            while (!s1.mpush(x))
            {
                s.bpush(s1.pop());
            }
        }
    }
    cout << "Sorted Stack:" << endl;
    s1.display();
    return 0;
}