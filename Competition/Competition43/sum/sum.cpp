#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    int n=read(),a=read(),tot=1,all;
    a=read(),all=n*(n+1)/2;
    if(a==0){
        for(int i = 1;i<=n;i++)cout<<0<<" ";
        return 0;
    }
    while(a!=n*tot){
        a-=2*tot;
        if(a<0){cout<<-1<<endl;return 0;}
        tot+=1;
        n-=2;
    }
    for(int i = 1;i<=tot-1;i++) cout<<0<<" ";
    cout<<1<<" ";
    for(int i = tot+1;i<=all;i++) cout<<0<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}