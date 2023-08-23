#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,k;
bool a[1000005];
int bob,alice=1;
int main(){
    int t=read();
    while(t--){
        n=read(),k=read();
        for(int i = 1,x;i<=n;i++){
            x=read();
            a[x]=true;
        }
        for(int i  = 1;i<=k;i++){
            while(a[bob])bob+=2;
            while(a[alice])alice+=2;
            a[bob]=true;
            a[alice]=true;
        }
        while(a[bob])bob+=2;
        while(a[alice])alice+=2;
        if(alice<bob){
            puts("Bob");
        }else{
            puts("Alice");
        }
        memset(a, 0 ,sizeof a);
        bob=0,alice=1;
    }
}