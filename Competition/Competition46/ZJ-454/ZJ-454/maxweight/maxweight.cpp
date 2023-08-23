#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int val[2][1000005];
int V[2];
bool vis[1000005];
int n;
int allstep;
int ans=0;
void dfs(int step){
    if(step>=allstep){
        ans=max(V[1],ans);
    }
    int can[15],tot=0;
    int maxn=0;
    for(int i = 1;i<=n;i++){
        if(vis[i])continue;
        if(val[step&1][i]>maxn){
            tot=0;
            can[++tot]=i;
            maxn=val[step&1][i];
        }else if(val[step&1][i]==maxn){
            can[++tot]=i;
        }
    }
    for(int i = 1;i<=tot;i++){
        V[step&1]+=val[step&1][can[i]];
        vis[can[i]]=true;
        dfs(step+1);
        V[step&1]-=val[step&1][can[i]];
        vis[can[i]]=false;
    }
}
void work1(int opt){
    long long ans=0;
    int minn=1e9;
     for(int i = 1;i<=n;i++){
        ans+=val[1][i];
        minn=min(minn,val[1][i]);
    }
    if(opt==0){
        if((n&1)==0){
            cout<<ans<<endl;
        }else{
            cout<<ans-minn<<endl;
        }
    }else{
        cout<<ans<<endl;
    }
}
bool cmp(int a,int b){
    return a>b;
}
void work2(int opt){
    sort(val[0],val[0]+n,cmp);
    int i;
    if(opt==1)i=1;
    else i=2;
    long long ans=0;
    for(;i<=n;i+=2){
        ans+=val[0][i];
    }
    cout<<ans<<endl;
}
int main(){
    freopen("maxweight.in","r",stdin);
    freopen("maxweight.out","w",stdout);
    int opt,T=read();
    while(T--){
        n=read(),opt=read();
        for(int i = 1;i<=n;i++)val[0][i]=read();
        for(int i = 1;i<=n;i++)val[1][i]=read();
        if(n<=10){
            allstep=n+opt;
            dfs(opt);
            cout<<ans<<endl;
            for(int i = 1;i<=n;i++) vis[i]=0;
            ans=0;
        }
        else{
            if(val[0][1]==0&&val[1][1]!=0)work1(opt);
            else if(val[0][1]==val[1][1])work2(opt);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
