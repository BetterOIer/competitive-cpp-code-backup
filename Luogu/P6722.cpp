#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
short col[100005];
bool vis[100005];
int cnt=0,n;
vector <int> ro[100005];
bool dfs(int now,int co){
    col[now]=co;
    cnt++;
    vis[now]=true;
    bool flag=true;
    for(auto i:ro[now]){
        if(col[i]==0){
            flag=dfs(i,3-co);
            if(!flag)return false;
        }
        else if(col[i]==co)return false;
    }
    return true;
}
int findnext(){
    for(int i = 1;i<=n;i++){
        if(!vis[i])return i;
    }
    return 0;
}
int main(){
    int t=read(),k,u,v,w;
    while(t--){
        n=read(),k=read();
        for(int i = 1;i<n;i++){
            u=read(),v=read(),w=read();
            if(w>=k){
                ro[u].push_back(v);
                ro[v].push_back(u);
            }
        }
        int po=1;
        while(cnt<n){
            bool flag=dfs(po,1);
            if(!flag){
                cout<<"Baka Chino\n";
                goto nex;
            }
            if(cnt<n){
                po=findnext();
                for(int i = 1;i<=n;i++){
                    col[i]=0;
                }
            }
        }
        cout<<"Yes\n";
        nex:
        for(int i = 0;i<=100004;i++){
            ro[i].clear();
            col[i]=0;
            vis[i]=0;
        }
        cnt=0;
    }
}
