#include <iostream>
#include <iterator>
#include <pthread.h>
using namespace std;
class Pattern
{
    int n;
    public:
        Pattern(int s){n = s;};
        void print();
};
void Pattern::print()
{
    for(int i=n-1;i>=0;i--)
    {
        for (int k=i; k<n-1; k++)
            cout<<" ";
        for (int j=1;j<=2*i+1;j++)
            cout<<"*";
        for (int k=i; k<n-1; k++)
            cout<<" "; 
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"\nEnter no of lines in pattern: ";
    cin>>n;
    Pattern ob(n);
    ob.print();
    return 0;
}

