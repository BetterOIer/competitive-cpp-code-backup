//#include<bits/stdc++.h>
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
#include <thread>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int mod = 1e9+7;
const int MAXN = 1e6+5;
const long long INF = 9223372036854775807ll;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int ti[MAXN],c[MAXN];
unsigned long long ans=0,a[MAXN],minx=INF;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n=read(),m=read(),l,r,s;
    for(int i = 1;i<=n;i++){
        l=read(),r=read(),s=read();
        a[l]+=s;
        a[r+1]-=s;
        ti[l]++;
        ti[r+1]--;
        ans+=s;
    }
    for(int i = 1;i<=m;i++){
        c[i]=c[i-1]+ti[i];
        if(!c[i]){
            cout<<ans;
            return 0;
        }
        a[i]+=a[i-1];
		minx=min(minx,a[i]);
    }
    cout<<ans-minx;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
