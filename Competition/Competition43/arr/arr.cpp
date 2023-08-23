#include<iostream>
using namespace std;
const int maxn = 5005;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
int poa[maxn],pob[maxn],poc[maxn];
int rea[maxn],reb[maxn],rec[maxn];
void getans(){
    int ans=0;
    for(int i = 1;i<=n;i++) ans+=labs(poa[i]-pob[i]);
    cout<<ans<<endl;
}
int main(){
    freopen("arr.in","r",stdin);
    freopen("arr.out","w",stdout);
    n=read(),m=read();
    for(int i = 1,k;i<=n;i++)k=read(),poa[k]=i,rea[i]=k;
    for(int i = 1,k;i<=n;i++)k=read(),pob[k]=i,reb[i]=k;
    for(int j = 1,opt,x,y;j<=m;j++){
        opt=read(),x=read();
        if(opt==2){
            y=read();
            swap(pob[reb[x]],pob[reb[y]]);
            swap(reb[x],reb[y]);
        }else if(opt==1){
            int i = 1;
            for(;i<=n-x;i++)rec[i]=rea[i+x], poc[rec[i]]=i;
            for(;i<=n;i++) rec[i]=rea[i+x-n],poc[rec[i]]=i;
            swap(poc,poa);
            swap(rec,rea);
        }
        getans();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}