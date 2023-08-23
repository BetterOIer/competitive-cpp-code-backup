#include <iostream>
#include <string>
using namespace std;
int len, sum;
bool d = 0;
char ysf[51];
int a[51] = {}, b[51] = {};
void pdws(int k)
{
    if (k <= 0)
    {
        len++;
    }
    while (k != 0)
    {
        k = (k - k % 10) / 10;
        sum++;
    }
    len += sum;
    sum = 0;
}
void jisuan(char a, int b, int c, bool d)
{
    len = 2, sum = 0;
    int t;
    if (a == 'a')
    {
        t = b + c;
        cout << b << '+' << c << '=' << t << endl;
    }
    else if (a == 'b')
    {
        t = b - c;
        cout << b << '-' << c << '=' << t << endl;
    }
    else if (a == 'c')
    {
        t = b * c;
        cout << b << '*' << c << '=' << t << endl;
    }
    pdws(b);
    pdws(c);
    pdws(t);
    if (!d)
    {
        cout << len << endl;
    }
    else
    {
        cout << len;
    }
}
int main()
{
    int i;
    cin >> i;
    for (int w = 1; w <= i; ++w)
    {
        string s;
        int j;
        cin >> s;
        if (s[0] == 'a' || s[0] == 'b' || s[0] == 'c')
        {
            ysf[w] = s[0];
            cin >> s;
            for (int j = 0; j <= s.length() - 1; ++j)
            {
                a[w] = 10 * a[w] + (s[j] - '0');
            }
            cin >> s;
            for (int j = 0; j <= s.length() - 1; ++j)
            {
                b[w] = 10 * b[w] + (s[j] - '0');
            }
        }
        else
        {
            ysf[w] = ysf[w - 1];
            for (int j = 0; j <= s.length()-1; ++j)
            {
                a[w] = 10 * a[w] + (s[j] - '0');
            }
            cin >> s;
            for (int j = 0; j <= s.length() - 1; ++j)
            {
                b[w] = 10 * b[w] + (s[j] - '0');
            }
        }
    }
    for (int w = 1; w <= i; ++w)
    {
        if (w == i)
        {
            d = 1;
        }
        jisuan(ysf[w], a[w], b[w], d);
    }
    return 0;
}