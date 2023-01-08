#include <iostream>
using namespace std;
class Square
{ 
    public:
       inline int sq(int x)
       {
           return x*x;
       }
};
int main()
{
    Square ob;
    int x;
    cout<<"\nEnter a number to be squared: ";
    cin>>x;
    cout<<"\nSquared: "<<ob.sq(x);
    return 0;
}
