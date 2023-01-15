#include <iostream>
#include <cmath>
using namespace std;
float volume(float side,int x)
{
    return pow(side,3);
}
float volume(float l, float b, float h)
{
    return l*b*h;
}
float volume(float r, float h,int s)
{
    return (M_PI*r*r*h)/3.0;
}
float volume(float r, float h)
{
    return (M_PI*r*r*h);
}
float volume(float r)
{
    return (4*M_PI*pow(r,3))/3.0;
}
int main()
{
    int ch;
    float length,breadth,side,radius,height;
    do
    {
        cout<<"\n1-cube\n2-cuboid\n3-cone\n4-cylinder\n5-sphere\n6-quit";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter length of cube edge: ";
                cin>>side;
                cout<<"Volume: "<<volume(side,1);
                break;
            case 2:
                cout<<"\nEnter length, breadth, height of cuboid: ";
                cin>>length>>breadth>>height;
                cout<<"Volume: "<<volume(length,breadth,height);
                break;
            case 3:
                cout<<"\nEnter radius and height of cone: ";
                cin>>radius>>height;
                cout<<"Volume: "<<volume(radius, height, 1);
                break;
            case 4:
                cout<<"\nEnter radius and height of cylinder: ";
                cin>>radius>>height;
                cout<<"Volume: "<<volume(radius, height);
                break;
            case 5:
                cout<<"\nEnter radius of sphere: ";
                cin>>radius;
                cout<<"Volume: "<<volume(radius);
                break;
            case 6:
                break;
            default:
                cout<<"\nInvalid choice!";
        }
    }while(ch!=6);
    return 0;
}