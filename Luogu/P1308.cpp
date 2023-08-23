#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, s1, s2;
    int sum = 0, location = 0, lo1, con = 0, len = 0;
    bool flag = 0;
    cin >> s;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        s[i] = tolower(s[i]);
    }
    cin.ignore(1024, '\n');
    getline(cin, s1);
    // len += s1.length() + 1;
    for (int i = 0; i <= s1.length() - 1; i++)     //xiaoxie
    {
        s1[i] = tolower(s1[i]);
    }
    for (int i = 0; i <= s1.length() - 1; i++)
    {
        len++;
        if (s1[i] != ' ')
        {
            con++;
            if (s1[i - 1] == ' '||i==0)
            {
                lo1 = i;
            }
        }
        else if (s1[i] == ' ')
        {
            s2 = s1.substr(lo1, con);
            if (s == s2)
            {
                sum++;
                if (!flag)
                {
                    location = len-s2.length()-1;
                    flag = 1;
                }
            }
            con=0;
        }
    }
    if (!sum)
    {
        cout << -1;
    }
    else
    {
        cout << sum << " " << location;
    }
    return 0;
}