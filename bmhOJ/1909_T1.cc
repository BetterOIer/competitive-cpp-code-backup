/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n, m, t[1000010], h[1000010], s[1000010], cnt[1000010], top;
int main(){
    n = read(); long long mx = 0, pos;
    for (long long i = 1; i <= n; i++) {
        t[i] = read(); if (t[i] > mx) {pos = i; mx = t[i];}
    }
    long long p = 0, ans = n - 1;
    for (long long i = pos + 1; i <= n; i++) h[++p] = t[i];
    for (long long i = 1; i < pos; i++) h[++p] = t[i];
    top = 0;
    for (long long i = 1; i <= p; i++) {
        while (s[top] < h[i] && top) ans += cnt[top--];
        if (s[top] != h[i]) s[++top] = h[i], cnt[top] = 0;
        ans += cnt[top]++;
    }
    while (top > 1) ans += cnt[top--];
    cout << ans;
    return 0;
}