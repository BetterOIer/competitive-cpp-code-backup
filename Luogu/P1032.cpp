#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct sb
{
    string ta, tb;
} t[7];
struct node
{
    string s;
    int time;
} w, u;
map<string, bool> map1;
string a, b;
queue<node> Q;
int main()
{
    cin >> a >> b;
    int oo = 1;
    while (cin >> t[oo].ta >> t[oo].tb)
        oo++;
    oo--;
    if (oo == -1 && a != b)
    {
        cout << "NO ANSWER!";
        return 0;
    }
    u.s = a, u.time = 0;
    Q.push(u);
    while (!Q.empty() && Q.front().time <= 10)
    {
        w = Q.front();
        if (map1[w.s] == 1)
        {
            Q.pop();
            continue;
        }
        map1[w.s] = 1;
        Q.pop();
        if (w.s == b)
        {
            cout << w.time;
            return 0;
        }
        for (int i = 1; i <= oo; i++)
        {
            string uu = w.s;
            int tl = t[i].ta.length(), oi;
            while (1)
            {
                oi = (int)uu.find(t[i].ta);
                if (oi == -1)
                    break;
                string ss = w.s;
                ss.replace(oi, tl, t[i].tb);
                u.s = ss;
                u.time = w.time + 1;
                Q.push(u);
                uu[oi] = '%';
            }
        }
    }
    cout << "NO ANSWER!";
    return 0;
}