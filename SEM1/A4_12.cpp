#include <iostream>
#include <string>
using namespace std;
class String
{
    string s;
    public:
        String(string w){s=w;}
        void display(){cout<<s<<endl;}
        String operator+(String s2);
};
String String::operator+(String s2)
{
    String temp("");
    temp.s = s+s2.s;
    int len=temp.s.length();
    string r=temp.s;
    for(int i=len-1;i>=0;i--)
        r[len-i-1]=temp.s[i];
    temp.s=r;
    return temp;
}
int main()
{
    string x,y;
    cout<<"\nString s1:"<<endl;
    cin>>x;
    cout<<"\nString s2:"<<endl;
    cin>>y;
    String s1(x),s2(y);
    s1.display();
    s2.display();
    String s3("");
    s3 = s1+s2;
    cout<<"\ns1 + s2 reversed:"<<endl;
    s3.display();
    return 0;
}