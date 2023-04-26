#include <iostream>
using namespace std;
class Num
{
    int x;

public:
    Num() { x = 0; }
    Num(int a) { x = a; }
    void print() { cout << x; }
    friend void nswap(Num &a, Num &b);
};
void nswap(Num &a, Num &b)
{
    a.x += b.x;
    b.x = a.x - b.x;
    a.x = a.x - b.x;
}
int main()
{
    int x, y;
    cout << "\nEnter 2 nos: ";
    cin >> x >> y;
    Num a(x), b(y);
    cout<<"\na: ";
    a.print();
    cout<<"\nb: ";
    b.print();
    cout<<"\n---After Swapping-----";
    nswap(a,b);
    cout<<"\na: ";
    a.print();
    cout<<"\nb: ";
    b.print();
    return 0;
}