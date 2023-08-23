#include <iostream>
using namespace std;
char a;
int main()
{
    while (cin >> a)
    {
        if (a >= 'a' && a <= 'z')
        {
            a = a + 'A' - 'a';
        }
        cout << a;
    }
    return 0;
}