#include <array>
#include <vector>
#include <iostream>
using namespace std;
array<int, 100005> h;
vector<int> c;
int main()
{
    int n;
    cin >> n;
    h[0] = 1000000005;
    c.push_back(0);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        while (h[i] >= h[*c.rbegin()])
            c.pop_back();
        ans += c.size();
        c.push_back(i);
    }
    cout << ans-n << endl;
}