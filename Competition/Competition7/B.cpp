#include<iostream>
using namespace std;
long long a[1000006];
struct node{
    int a,b;
}ds[1000006];
int main(){
    int n,k,q,l,r,L=134534,R=0;
    cin>>n>>k>>q;
    for(int i = 1;i<=n;i++){
        cin>>l>>r;
        L=min(l,L),R=max(r,R);
        for(int j = l;j<=r;j++) a[j]++;
    }
    for(int i = 1;i<=q;i++){
        cin>>l>>r;
        L=min(l,L),R=max(r,R);
        ds[i].a=l,ds[i].b=r;
    }
    for(int i = L;i<=R;i++){
        if(a[i]>=k) a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    }
    for(int i = 1;i<=q;i++){
        cout<<a[ds[i].b]-a[ds[i].a-1]<<endl;
    }
    return 0;
}