#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <array>
using namespace std;
const int mod = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 2147483647;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[11],m;
long long ans=0;
long long n;
set <long long> s;
queue <long long> Q;
int main(){
    freopen("T265202.in","r",stdin);
    freopen("T265202.out","w",stdout);
    n=read(),m=read();
    for(int i = 1;i<=m;i++){
        a[i]=read();
    }
    m=unique(a+1,a+m+1)-a+1;
    s.insert(n);
    Q.push(n);
    ans++;
    while(!Q.empty()){
        long long now=Q.front(),cnt;
        Q.pop();
        for(int i = 1;i<=m;i++){
            cnt=now/a[i];
            if(s.find(cnt)==s.end()){
                s.insert(cnt);
                Q.push(cnt);
                ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
