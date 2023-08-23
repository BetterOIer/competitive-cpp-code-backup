#include <iostream>
#include <string>
using namespace std;
bool flag1[256] = {};
bool flag2[256] = {};
int boy(string s)
{
    int sumb = 0;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (s[i] == 'g' || s[i] == 'i' || s[i] == 'r' || s[i] == 'l' || s[i] == '.')
        {
            flag1[i] = 1;
        }
    }
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (!flag1[i])
        {
            if (s[i] == 'b')
            {
                flag1[i] = 1;
                if (s[i + 1] == 'o')
                {
                    flag1[i + 1] = 1;
                    if (s[i + 2] == 'y')
                    {
                        flag1[i + 2] = 1;
                        sumb++;
                    }
                    else
                    {
                        sumb++;
                    }
                }
                else
                {
                    sumb++;
                }
            }
            else if (s[i] == 'o')
            {
                flag1[i] = 1;
                if (s[i + 1] == 'y')
                {
                    flag1[i + 1] = 1;
                    sumb++;
                }
                else
                {
                    sumb++;
                }
            }
            else if (s[i] == 'y')
            {
                flag1[i] = 1;
                sumb++;
            }
        }
    }
    return sumb;
}
int girl(string s)
{
    int sumg = 0;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (s[i] == 'b' || s[i] == 'o' || s[i] == 'y' || s[i] == '.')
        {
            flag2[i] = 1;
        }
    }
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (!flag2[i])
        {
            if (s[i] == 'g')
            {
                flag2[i] = 1;
                if (s[i + 1] == 'i')
                {
                    flag2[i + 1] = 1;
                    if (s[i + 2] == 'r')
                    {
                        flag2[i + 2] = 1;
                        if (s[i + 3] == 'l')
                        {
                            flag2[i + 3] = 1;
                            sumg++;
                        }
                        else
                        {
                            sumg++;
                        }
                    }
                    else
                    {
                        sumg++;
                    }
                }
                else
                {
                    sumg++;
                }
            }
            else if (s[i] == 'i')
            {
                flag2[i] = 1;
                if (s[i + 1] == 'r')
                {
                    flag2[i + 1] = 1;
                    if (s[i + 2] == 'l')
                    {
                        flag2[i + 2] = 1;
                        sumg++;
                    }
                    else
                    {
                        sumg++;
                    }
                }
                else
                {
                    sumg++;
                }
            }
            else if (s[i] == 'r')
            {
                flag2[i] = 1;
                if (s[i + 1] == 'l')
                {
                    flag2[i + 1] = 1;
                    sumg++;
                }
                else
                {
                    sumg++;
                }
            }
            else if (s[i] == 'l')
            {
                flag2[i] = 1;
                sumg++;
            }
        }
    }
    return sumg;
}
int main()
{
    string s;
    cin >> s;
    cout << boy(s) << endl
         << girl(s);
    return 0;
}