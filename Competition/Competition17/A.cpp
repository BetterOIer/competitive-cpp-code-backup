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
const long long mod = 1e7+7;
const long long MAXN = 1e6+5;
const long long INF = 2147483647;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
priority_queue<long long,vector<long long>,less<long long> > q;
signed main(){
    long long T=read(),n,ans;
    for(;T--;){
        ans=0;
        n=read();
        while(!q.empty())q.pop();
        for(long long i = 1;i<=n;i++){
            q.push(read());
        }
        while(1){
            long long a=q.top();
            q.pop();
            long long b=q.top();
            q.pop();
            long long c=a+b;
            if(c<0) break;
            q.push(c);
            ans=(ans+c)%mod;
            if(q.size()==1){
                q.pop();
                break;
            }
        }
        if(ans>0)cout<<ans<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
