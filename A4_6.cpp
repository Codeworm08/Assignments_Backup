#include <iostream>
using namespace std;
class Leap
{
    int year;
    public:
        Leap(int y){year=y;}
        ~Leap();
};
Leap::~Leap()
{
    if (year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
                cout<<"\nLeap year";
            else
                cout<<"\nNot Leap year";
        }
        else
            cout<<"\nLeap Year";   
    }
    else
        cout<<"Not Leap year";
}
int main()
{
    int year;
    cout<<"\nEnter year: ";
    cin>>year;
    Leap l(year);
    return 0;
}