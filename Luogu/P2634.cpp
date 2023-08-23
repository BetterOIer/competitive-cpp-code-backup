#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
inline void write(long long qw){
    if (qw < 0){
        putchar('-');
        qw = -qw;
    }
    if (qw > 9) write(qw / 10);
    putchar(qw % 10 + '0');
}
struct node{
    int to, next, len;
} t[40009];
int head[20007], cnt;
int sim[20007], mxson[20007], sum[4];
long long ans;
int Sumer, MX, dec1, root, n;
bool vis[20007];
void addedge(int u, int v, int l){
    cnt++;
    t[cnt].to = v;
    t[cnt].next = head[u];
    t[cnt].len = l;
    head[u] = cnt;
    return;
}
void getroot(int now, int fa){
    sim[now] = 1,mxson[now] = 0;
    for (int i = head[now]; i; i = t[i].next){
        int v = t[i].to;
        if (v == fa || vis[v]) continue;
        getroot(v, now);
        sim[now] = sim[now] + sim[v];
        mxson[now] = max(mxson[now], sim[v]);
    }
    mxson[now] = max(mxson[now], Sumer - sim[now]);
    if (mxson[now] < MX) MX = mxson[now],root = now;
}
void query(int u, int fa, int depth){
    sum[depth % 3]++;
    for (int i = head[u]; i; i = t[i].next){
        int v = t[i].to;
        if (vis[v] || v == fa) continue;
        query(v, u, (depth + t[i].len) % 3);
    }
    return;
}
long long solve(int st, int len){
    sum[0] = sum[1] = sum[2] = 0;
    query(st, 0, len);
    long long tep = 2 * sum[1] * sum[2] + sum[0] * (sum[0] - 1) + sum[0];
    return tep;
}

void Divide(int now){
    ans = ans + solve(now, 0);
    vis[now] = true;
    for (int i = head[now]; i; i = t[i].next){
        int v = t[i].to;
        if (vis[v]) continue;
        ans = ans - solve(v, t[i].len);
        MX = 2147483646;
        root = 0;
        Sumer = sim[v];
        getroot(v, 0);
        Divide(root);
    }
    return;
}

void gcd(long long a, long long b){
    if (b == 0) dec1 = a;
    else gcd(b, a % b);
}
int main(){
    n = read();
    for (int i = 1; i <= n - 1; i++){
        int u = read(), v = read(), l = read() % 3;
        addedge(u,v,l);
        addedge(v,u,l);
    }
    MX = 2147483646;
    root = 0;
    Sumer = n;
    ans = 0;
    getroot(1, 0);
    Divide(root);
    long long tep1 = n * n;
    gcd(ans, tep1);
    write(ans/dec1);
    putchar('/');
    write(tep1/dec1);
    return 0;
}