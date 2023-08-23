#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005],b[100005],ans=0;
int find(int x,int L,int R){
    if(L==R) return L;
    else if(L+1==R){
        if(x-b[L]>b[R]-x){
            return R;
        }else return L;
    }
    int M = L+(R-L)/2;
    if(b[M]<x){
        return find(x,M,R);
    }else if(b[M]>x){
        return find(x,L,M);
    }else if(b[M]==x){
        return M; 
    }
    return 0;
}
int main(){
    int n,m;
    cin>>m>>n;
    for(int i = 1;i<=m;i++)cin>>b[i];
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i = 1;i<=n;i++){
        ans+=abs(a[i]-b[find(a[i],1,m)]);
    }
    cout<<ans;
    return 0;
}
