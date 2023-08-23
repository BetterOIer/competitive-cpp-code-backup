#include <iostream>
using namespace std;
struct people
{
    string name;
    int dir;
};
int main()
{
    int m, n, flag = 0;
    cin >> m >> n;
    people a[m];
    for (int i = 0; i <= m - 1; ++i)
    {
        cin >> a[i].dir >> a[i].name;
    }
    for (int i = 0; i <= n - 1; ++i)
    {
        int cx, bs;
        cin >> cx >> bs;
        if (a[flag].dir == cx)
        {
            flag -= bs;
        }
        else
        {
            flag += bs;
        }
        while (flag < 0)
        {
            flag += (m);
        }
        while (flag > m-1)
        {
            flag -= (m);
        }
    }

    cout << a[flag].name;
    return 0;
}