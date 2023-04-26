#include <iostream>
using namespace std;
class Complex
{
    int r,i;
    public:
    void input()
    {
        cout<<"\n\tReal: ";
        cin>>r;
        cout<<"\n\tImaginary: ";
        cin>>i;
    }
    void print(){cout<<r<<" + i"<<i;}
    friend Complex operator+ (Complex c1, Complex c2);
};
Complex operator+ (Complex c1, Complex c2)
{
    Complex c3;
    c3.r = c1.r + c2.r;
    c3.i = c1.i + c2.i;
    return c3;
}
int main()
{
    Complex c1, c2;
    cout<<"\n1st Complex number:";
    c1.input();
    cout<<"\n2nd Complex number:";
    c2.input();
    c1.print();
    cout<<endl<<"+"<<endl;
    c2.print();
    Complex c3=c1+c2;
    cout<<endl<<"="<<endl;
    c3.print();
    return 0;
}

