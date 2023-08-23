#include <iostream>
using namespace std;
int main()
{
    int n;
    string s1, s2, s3;
    string a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s1;
        s2 = s1;
        for (int w = 0; w <= s1.length() - 1; ++w)
        {
            a += s2[0];
            s2 += a;
            for (int j = 0; j <= s2.length() - 1; ++j)
            {
                s2[j] = s2[j + 1];
            }
            if (s2 < s1)
            {
                s1 = s2.substr(0, s2.length() - 1);
            }
            s2 = s2.substr(0, s2.length() - 1);
            a = "";
        }
        cin >> s3;

        if (s1 == s3)
        {
            cout << "gefan is Biology Master!!!" << endl;
        }
        else
        {
            cout << "Wrong Answer!!!" << endl
                 << s1 << endl;
        }
    }
    return 0;
}