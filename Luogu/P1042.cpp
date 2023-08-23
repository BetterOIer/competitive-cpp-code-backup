#include <iostream>
#include <cmath>
using namespace std;
void pd(string &s, const int n, int &w,int &l)
{
    if (s[0] == 'W')
    {
        w++;
        s = s.substr(1, s.length() - 1);
    }
    else if (s[0] == 'L')
    {
        l++;
        s = s.substr(1, s.length() - 1);
    }
}
void comp(string s, const int n)
{
    bool flag = 0;
    while (!flag)
    {
        int w = 0, l = 0, i = 0;
        int t = s.length()-1;
        for (;(w<n&&l<n)&&i<=t; ++i)
        {
            pd(s,n,w,l);
        }
        while (abs(w - l) < 2&&i<=t)
        {
            pd(s,n,w,l);
            i++;
            if(i==t){
                flag = 1;
            }
        }
        cout << w << ':' << l << endl;
        if(i>=t){
            flag=1;
        }
        //if (s.length() < n&&flag != 1)
        //{
        //    int w = 0, l = 0;
        //    for (int i = 0; i <= s.length() - 1; ++i)
        //    {
        //        pd(s,n,w,l);
        //    }
        //    cout << w << ':' << l << endl;
        //    flag = 1;
        //}
    }
    cout << endl;
}
int main()
{
    string s_enter, s, s1;
    bool flag = true;
    while (cin >> s_enter)
    {
        if (s_enter.find('E') != -1)
        {
            s_enter = s_enter.substr(0, s_enter.find('E'));
            s += s_enter;
            flag = false;
        }
        if (flag)
        {
            s += s_enter;
        }
    }
    s1 = s;
    comp(s, 11);
    comp(s1, 21);
    return 0;
}