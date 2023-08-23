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
using namespace std;
const int mod = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 2147483647;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[100000005];
int po(int x,long long ans){
    
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n=read();
    long long ans=0,cnt=0;
    for(int i = 1;i<=n;i++){
        a[i]=i;
    }
    do{
        ans=0;
        for(int i = 1;i<n;i++){
            for(int j = i;j<=n;j++){
                if(a[i]>a[j]){
                    ans++;
                }
            }
        }
        cnt=(cnt+(int)pow(2,ans))%1000000007;
    }
    while(next_permutation(a+1,a+n+1));
    cout<<cnt;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
