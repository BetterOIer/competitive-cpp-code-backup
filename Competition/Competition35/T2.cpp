#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector<int>tree[400005];
vector<pair<int,int> > edge;
bool canbe[400005];
bool belong[400005];
int refer[2][400005];
int son[400005],ans,id[400005],len,p[400005],lenp;
bool v[400005];
void gettree(int x,int fa,int x1,int x2,int co){
    belong[x]=co;
    refer[co][++refer[co][0]]=x;
    for(auto i:tree[x]){
        if(fa==i)continue;
        if((x==x1&&i==x2)||(x==x2&&i==x1)) continue;
        gettree(i,x,x1,x2,co);
    }
}
int dfs(int x,int x1,int x2,int x3,int x4){
    if(!tree[x].size()) return 1;
    int sum=0;
    for(auto i:tree[x]){
        if(v[i])continue;
        if((x==x1&&i==x2)||(x==x2&&i==x1)) continue;

        v[i]=1;
        sum+=dfs(i,x1,x2,x3,x4);
    }
    if(x==x3){
        if(v[x4]){
            v[x4]=1;
            sum+=dfs(x4,x1,x2,x3,x4);
        }
    }
    if(x==x4){
        if(v[x3]){
            v[x3]=1;
            sum+=dfs(x3,x1,x2,x3,x4);
        }
    }
    return sum+1;
}
int main(){
    freopen("reform.in","r",stdin);
    freopen("reform.out","w",stdout);
    int t=read();
    while(t--){
        int n=read();
        for(int i = 1,u,v;i<n;i++){
            u=read(),v=read();
            tree[u].push_back(v);
            tree[v].push_back(u);
            edge.push_back({u,v});
        }
        for(auto o:edge){
            gettree(o.first,0,o.first,o.second,1);
            gettree(o.second,0,o.first,o.second,0);
            for(int w = 1;w<=refer[0][0];w++){
                for(int j = 1;j<=refer[1][0];j++){
                    for(int i=1;i<=n;i++){
                            memset(v,0,sizeof(v));
                            v[i]=1;
                            son[i]=dfs(i,o.first,o.second,w,j);
                        }
                        int minn=0x3f3f3f3f;
                        for(int i=1;i<=n;i++)
                        {
                            int maxn=n-son[i];
                            for(auto ww:tree[i]){
                                if((i==o.first&&ww==o.second)||(ww==o.first&&i==o.second)) continue;
                                maxn=max(maxn,son[ww]);
                            }
                            if(i==w)maxn=max(maxn,son[j]);
                            if(i==j)maxn=max(maxn,son[w]);
                            minn=min(maxn,minn);
                            p[i]=maxn;
                        }
                        for(int i=1;i<=n;i++)
                        {
                            if(p[i]==minn)
                            {
                                canbe[i]=true;
                            }
                        }
                    
                }
            }
        }
        for(int i = 1;i<=n;i++){
            if(canbe[i])cout<<1<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}