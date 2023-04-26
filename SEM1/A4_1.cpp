#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14;
class Area
{
    private:
        float n;
    protected:
        float prad;
    public:
        float rad;
        void setPriv(float x);
        void cal_area();
};
void Area::setPriv(float x)
{
    n=x;
}
void Area::cal_area()
{
    float priv_area= M_PI*pow(n,2);
    cout<<"\nArea with private member: "<<priv_area;
}

class InheritedCircle:public Area
{
    public:
        void cal(float x);
};
void InheritedCircle::cal(float x)
{
    prad=x;//using protected member
    float pro_area = M_PI*pow(prad,2);
    cout<<"\nArea using protected member: "<<pro_area;
}
int main()
{
    float radius;
    Area ob;
    InheritedCircle c;
    cout<<"\nEnter radius: ";
    cin>>radius;
    ob.rad=radius;
    ob.setPriv(radius);
    ob.cal_area();
    c.cal(radius);
    cout<<"\nArea using public member: "<<M_PI*pow(ob.rad,2);
    return 0;
}
