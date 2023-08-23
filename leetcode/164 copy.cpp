#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0;char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x;
}
unordered_map<int,int>s;
int n;
int f[1000006],pre[5000006];
//char In[6],Out[6];
int main(){
//    cin>>Out[0];
//    In[0]=Out[0];
//    In[1]=Out[1]='.';
//    In[2]='i';Out[2]='o';
//    In[3]='n',Out[3]='u';
//    Out[4]='t';
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
    n=read();
    for(int i=2;i<=n+1;++i){
        int w=read();
        pre[i]=w^pre[i-1];
    }
    s[0]=1;
    for(int i=2;i<=n+1;++i){
        if(pre[i]==pre[i-1])f[i]=f[i-1]+1;
        else if(!s[pre[i]])f[i]=f[i-1];
        else{
            f[i]=max(f[i-1],f[s[pre[i]]]+1);
        }
        s[pre[i]]=i;
    }
    printf("%d",f[n+1]);
    return 0;
}