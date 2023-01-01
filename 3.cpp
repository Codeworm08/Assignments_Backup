#include <iostream>
using namespace std;
class Number_List
{
    int n;
    int *arr;

public:
    Number_List(int x) { n = x; };
    void create_dyn();
    void sort();
    void print();
    int min();
    int max();
};
void Number_List::create_dyn()
{
    arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
void Number_List::print()
{
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void Number_List::sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int Number_List::min()
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int Number_List::max()
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int n;
    cout << "Enter no of elements: ";
    cin >> n;
    Number_List ob(n);
    ob.create_dyn();
    cout << "Array: ";
    ob.print();
    cout << "\nSorted Array:";
    ob.sort();
    ob.print();
    cout << "\nMinimum element: " << ob.min();
    cout << "\nMaximum element: " << ob.max();
    return 0;
}