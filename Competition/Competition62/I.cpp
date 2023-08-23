#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int a[100],n,cnt;
int dfs(int pos,int sum,int num,bool limit){
    if(pos==0){
        return sum%num==0;
    }
    int res=0,maxn=limit?a[pos]:1;
    for(int i=0;i<=maxn;i++){
        res+=dfs(pos-1,sum*2+i,num+(i==1),limit&&(i==maxn));
    }
    return res;
}
int solve(int n){
    int m=n;
    while(n){
        a[++cnt]=n%2;
        n/=2;
    }
    return dfs(cnt,1,1,1);
}
int main(){
    n=read();
    cout<<solve(n);
}