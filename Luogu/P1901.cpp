#include <iostream>
using namespace std;
const int maxn=1000006;
int s1[maxn],h[maxn],v[maxn],sum[maxn],ans,n,top;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i] >> v[i];
        while (top && h[s1[top]] < h[i])
            sum[i] += v[s1[top--]];
        sum[s1[top]] += v[i];
        s1[++top] = i;
    }
    for (int i = 1; i <= n; i++) ans = max(ans, sum[i]);
    cout << ans;
    return 0;
}