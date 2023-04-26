#include <iostream>
#include <string>
using namespace std;
class String
{
    string s;

public:
    String() { s = ""; };
    String(string w) { s = w; }
    void display();
    friend String join(String s1, String s2);
};
void String::display()
{
    cout << s;
}
String join(String s1, String s2)
{
    String s3;
    s3.s = s1.s + s2.s;
    return s3;
}
int main()
{
    string w1, w2;
    cout << "\nEnter 1st string: ";
    cin >> w1;
    cout << "\nEnter 2nd string: ";
    cin >> w2;
    String s1(w1), s2(w2);
    cout << "\n1st String: ";
    s1.display();
    cout << "\n2nd String: ";
    s2.display();
    String s3=join(s1,s2);
    cout<<"\ns1+s2:\n";
    s3.display();
    return 0;
}