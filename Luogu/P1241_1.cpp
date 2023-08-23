#include <bits/stdc++.h>
using namespace std;
stack<int> Q;
bool a[105];
int main()
{
    string s;
    cin >> s;
    for (int i = 0, k; i < s.length(); i++)
    {
        if (s[i] == ']')
        {
            if (Q.empty())
                continue;
            k = Q.top();
            if (s[k] == '[')
            {
                a[k] = a[i] = 1;
                Q.pop();
            }
        }
        else if (s[i] == ')')
        {
            if (Q.empty())
                continue;
            k = Q.top();
            if (s[k] == '(')
            {
                a[k] = a[i] = 1;
                Q.pop();
            }
        }
        else
            Q.push(i);
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (a[i])
            cout << s[i];
        else
        {
            if (s[i] == '(' || s[i] == ')')
                printf("()");
            else
                printf("[]");
        }
    }
    return 0;
}
