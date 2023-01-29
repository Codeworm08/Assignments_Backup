#include <iostream>
using namespace std;
#define SIZE 100

class Stack
{
protected:
    int st[SIZE];
    int top;

public:
    Stack() { top = 0; }
    void display();
    void display(int p);
    void push(int p);
    int pop();
    void peek();
};
void Stack::display()
{
    if (!top)
    {
        cout << "Stack empty!" << endl;
        return;
    }
    for (int i = top - 1; i > 0; i--)
        cout << st[i] << "->";
    cout << st[0] << endl;
}
void Stack::display(int p)
{
    if (p >= 0 && p < top)
        cout << "Element at depth "<<p<< ": " << st[top - 1 - p] << endl;
    else
        cout << "Depth " << p << " does not exist in Stack." << endl;
}
void Stack::push(int p)
{
    if (top == SIZE)
    {
        cout << "Stack Overflow!" << endl;
        return;
    }
    st[top] = p;
    top++;
}
int Stack::pop()
{
    if (!top)
    {
        cout << "Stack Empty!" << endl;
        return -1;
    }
    cout << "\nElement popped: " << st[top - 1] << endl;
    int p = st[top - 1];
    top--;
    return p;
}
void Stack::peek()
{
    if (top)
        cout << st[top - 1] << endl;
    else
        cout << "Empty stack!" << endl;
}
class Special : public Stack
{
public:
    int mpush(int p);
};
int Special::mpush(int p)
{
    if (top == 0)
    {
        push(p);
        return 1;
    }
    if (st[top - 1] > p)
    {
        push(p);
        return 1;
    }
    cout << p << " Not less than top of stack." << endl;
    return 0;
}
int main()
{
    Special s, s1, s2;
    int ch;
    do
    {
        cout << "\nEnter integer to push(-1 to quit): ";
        cin >> ch;
        if (ch >= 0)
            s.push(ch);
    } while (ch != -1);
    // s.display();
    while (true)
    {
        int x = s.pop();
        if (x == -1)
            break;
        if (!s1.mpush(x))
        {
            s2.push(x);
            s.push(s1.pop());
            while (!s1.mpush(x))
            {
                s.push(s1.pop());
            }
        }
        /* cout<<x<<":"<<endl;
        s1.display();
        s2.display(); */
    }
    cout << "Sorted Stack:" << endl;
    s1.display();
    return 0;
}