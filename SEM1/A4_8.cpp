#include <iostream>
using namespace std;
class b
{
public:
    b() { cout << "\nBase class constrctor!"; }
    virtual ~b() { cout << "\nDeconstructing base class!"; }
};
class d : public b
{
    int x;

public:
    d() { x = 0; }
    d(d &ob)// Copy Constructor
    {
        cout << "\nIn copy constructor.";
        x = ob.x;
    } 
    d(int s)// Parameterized Constructor
    {
        cout << "\nIn parameterized constructor.";
        x = s;
    } 
};
int main()
{
    b *o;
    int n;
    cout << "\nEnter a number: ";
    cin >> n;
    o = new d();
    d ob(n);
    d ob2 = ob;
    delete o;
    return 0;
}