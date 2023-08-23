#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int a[10],ans;
int main(){
    for(int i=1;i<=8;i++){
        a[i]=read();
        if(a[i]==9)ans=1;
    }
    if(ans==1)cout<<"F"<<endl;
    else cout<<"S"<<endl;
}