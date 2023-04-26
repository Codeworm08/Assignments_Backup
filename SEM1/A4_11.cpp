#include <iostream>
using namespace std;
void calculate(char ch, int m)
{
    int rev, r = 0;
    while (m != 0)
    {
        r = m % 10;
        rev = rev * 10 + r;
        m /= 10;
    }
    cout << "\nReverse: " << rev;
}
void calculate(int m, char ch)
{
    int p = 1;
    for (int i = 2; i < m / 2; i++)
    {
        if (m % i == 0)
        {
            p = 0;
            break;
        }
    }
    if (p)
        cout << "\nIs Prime";
    else
        cout << "\nNot prime";
}

int main()
{
    char ch;
    int m;
    cout << "\nEnter a number: ";
    cin >> m;
    cout << "\nr->Reverse digits\np->Check prime";
    cin >> ch;
    switch (ch)
    {
    case 'r':
        calculate(ch, m);
        break;
    case 'p':
        calculate(m, ch);
        break;
    default:
        cout << "\nInvalid input.";
    }
    return 0;
}