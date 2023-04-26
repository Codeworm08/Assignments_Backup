#include <iostream>
#include <cmath>
using namespace std;
class Triangle
{
    float a,b,c,area,perimeter;
    public:
        void input();
        void cal_perimeter();
        void cal_area();
        void print();
};
void Triangle::input()
{
    cout<<"Enter values of the 3 sides: ";
    cin>>a>>b>>c;
}
void Triangle::cal_area()
{
    float s=(a+b+c)/2;
    cout<<s<<" "<<s-a<<" "<<s-b<<" " <<s-c;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
}
void Triangle::cal_perimeter()
{
    perimeter=a+b+c;
}
void Triangle::print()
{
    cout<<"\nSides: "<<a<<" "<<b<<" "<<c;
    cout<<"\nArea: "<<area;
    cout<<"\nPerimeter: "<<perimeter;
}
int main()
{
    Triangle ob;
    ob.input();
    ob.cal_area();
    ob.cal_perimeter();
    ob.print();
    return 0;
}
