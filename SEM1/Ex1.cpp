#include <iostream>
using namespace std;
#define SIZE 100

class Stack
{
    protected:
        int st[SIZE];
        int top;
    public:
        Stack(){top=0;}
        void display();
        void display(int p);
        void push(int p);
        int pop();
        void peek();
};
void Stack::display()
{
    if(!top)
    {
        cout<<"Stack empty!"<<endl;
        return;
    }
    for(int i=top-1;i>0;i--)
        cout<<st[i]<<"->";
    cout<<st[0]<<endl;
}
void Stack::display(int p)
{
    if(p>=0 && p<top)
        cout<<"Element at depth p: "<<st[top-1-p]<<endl;
    else
        cout<<"Depth "<<p<<" does not exist in Stack."<<endl;
}
void Stack::push(int p)
{
    if(top==SIZE)
    {
        cout<<"Stack Overflow!"<<endl;
        return;
    }
    st[top]=p;
    top++;
}
int Stack::pop()
{
    if(!top)
    {
        cout<<"Stack Empty!"<<endl;
        return -1;
    }
    cout<<"\nElement popped: "<<st[top-1]<<endl;
    int p = st[top-1];
    top--;
    return p;
}
void Stack::peek()
{
    if(top)
        cout<<st[top-1]<<endl;
    else
        cout<<"Empty stack!"<<endl;
}
int main()
{
    Stack s1;
    int p,pos,ch;
    do
    {
        cout<<"\n1->push\n2->pop\n3->display()\n4->display(depth)\n5->peek\n0->quit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 0: break;
            case 1:
                cout<<"Enter number to insert: ";
                cin>>p;
                s1.push(p);
                break;
            case 2:
                p=s1.pop();
                if(p>=0)
                    cout<<"Popped: "<<p<<endl;
                break;
            case 3:
                s1.display();
                break;
            case 4:
                cout<<"Enter depth to display: ";
                cin>>p;
                s1.display(p);
                break;
            case 5:
                s1.peek();
                break;
            default:
                cout<<"\nInvalid choice.";
        }
    }while(ch);
    return 0;
}