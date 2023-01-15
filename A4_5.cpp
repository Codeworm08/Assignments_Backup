#include <iostream>
using namespace std;
class Complex
{
    int real,imaginary;
    public:
        Complex(){real=0;imaginary=0;}
        Complex(int a){real=a;imaginary=a;}
        Complex(int r,int i){real=r;imaginary=i;}
        void show();
        void sum(Complex c2);
};
void Complex::show()
{
    cout<<"\n"<<real<<" + i"<<imaginary<<endl;
}

void Complex::sum(Complex c2)
{
    Complex c3;
    c3.real = real + c2.real;
    c3.imaginary = imaginary + c2.imaginary;
    c3.show();
}
int main()
{
    Complex c1,c2(4,5),c3(4);
    cout<<"c1: ";
    c1.show();
    cout<<"c2: ";
    c2.show();
    cout<<"c3: ";
    c3.show();
    cout<<"\nc1+c2:";
    c1.sum(c2);
    cout<<"\nc1+c3:";
    c1.sum(c3);
    cout<<"\nc2+c3:";
    c2.sum(c3);
    return 0;
}