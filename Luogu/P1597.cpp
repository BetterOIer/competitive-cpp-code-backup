#include <iostream>
#include <string>
using namespace std;

void pdfz(string s, int &a,int &b,int &c)
{
    if (s[0] == 'a')
    {
        if (s[3] == 'a')
        {
            a = a;
        }
        else if (s[3] == 'b')
        {
            a = b;
        }
        else if (s[3] == 'c')
        {
            a = c;
        }
        else
        {
            a = s[3] - '0';
        }
    }
    else if (s[0] == 'b')
    {
        if (s[3] == 'a')
        {
            b = a;
        }
        else if (s[3] == 'b')
        {
            b = b;
        }
        else if (s[3] == 'c')
        {
            b = c;
        }
        else
        {
            b = s[3] - '0';
        }
    }
    else if (s[0] == 'c')
    {
        if (s[3] == 'a')
        {
            c = a;
        }
        else if (s[3] == 'b')
        {
            c = b;
        }
        else if (s[3] == 'c')
        {
            c = c;
        }
        else
        {
            c = s[3] - '0';
        }
    }
}
int main()
{
    string s;
    int a = 0, b = 0, c = 0, d;
    cin >> s;
    d = s.length();
    for (int i = 0; i <= d / 5 - 1; i++)
    {
        string s1 = s.substr(0, 5);
        s = s.substr(5, s.length() - 5);
        pdfz(s1, a, b, c);
    }
    cout << a << " " << b << " " << c;
    return 0;
}