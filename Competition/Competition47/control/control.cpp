#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,k,q,nowk=0;
int origin[3005],usin[3005];
void LT(){
    while(true){

    }
}
int main(){
    n=read(),k=read(),q=read();
    for(int i = 1;i<=n;i++){
        origin[i]=read();
    }
    for(int i = 1,l,r;i<=q;i++){
        l=read(),r=read(),nowk=0;
        for(int u = l;u<=r;i++)if(origin[u]==1)nowk++;
        if(nowk<=k){cout<<0<<endl;continue;}
        for(int u = 1;u<=n;u++)usin[u]=origin[u];
        Temper=3000;
        LT();
    }
    return 0;
}