#include <iostream>
using namespace std;
class Time
{
    int h, m, s;

public:
    friend istream &operator>>(istream &is, Time &t);
    Time operator+(Time t2);
    friend ostream &operator<<(ostream &os, const Time &t);
    bool operator==(const Time t2);
};
istream &operator>>(istream &is, Time &t)
{
    cout << "\n\tHours: ";
    is >> t.h;
    cout << "\n\tMinutes: ";
    is >> t.m;
    cout << "\n\tSeconds: ";
    is >> t.s;
    return is;
}
Time Time::operator+(Time t2)
{
    Time temp;
    temp.s=(s+t2.s)%60;
    temp.m=(m+t2.m+((s+t2.s)/60))%60;
    temp.h=(h+t2.h+((m+t2.m+((s+t2.s)/60))/60));
    return temp;
}
ostream &operator<<(ostream &os,const Time &t)
{
    os<<"\n\t"<<t.h<<":"<<t.m<<":"<<t.s;
    return os;
}
bool Time::operator==(const Time t2)
{
    if(h==t2.h&&m==t2.m&&s==t2.s)
        return true;
    return false;
}
int main()
{
    Time t1,t2;
    cout<<"\nTime 1:";
    cin>>t1;
    cout<<"\nTime 2:";
    cin>>t2;
    cout<<"\nt1: "<<t1<<"\nt2: "<<t2;
    Time t3 = t1+t2;
    cout<<"\nt1+t2= "<<t3;
    cout<<"\nt1==t2: ";
    if(t1==t2)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}
