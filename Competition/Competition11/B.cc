#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m,p1,s1,s2,k=1;
long long x=0,y=0,ANS=0;
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    cin>>m>>p1>>s1>>s2;
    if(s2==0){
        cout<<1;
        return 0;
    }
    for(int i = 1;i<=m-1;i++) x+=a[i]*(m-i);
    for(int i = m+1;i<=n;i++) y+=a[i]*(i-m);
    if(p1<m) x+=s1*(m-p1);
    else if(p1>m) y+=s1*(p1-m);
    ANS=abs(x-y);
    if(ANS==0) {cout<<m;return 0;}
    for(int i = 1;i<=n;i++){
        if(i<=m){
            long long now=x+s2*(m-i);
            if(abs(now-y)<ANS){
                k=i;
                ANS=abs(now-y);
            }
        }else if(i>=m){
            long long now=y+s2*(i-m);
            if(abs(now-x)<ANS){
                k=i;
                ANS=abs(now-x);
            }
        }
    }
    cout<<k;
}