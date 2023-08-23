#include<iostream>
#include<vector>
using namespace std;
short col[10005];
bool vis[10005];
int cnt=0,n,m;
vector <int> ro[10005];
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
    int u,v;
    cin>>n>>m;
    for(int i =1;i<=m;i++){
        cin>>u>>v;
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    int ANS=0;
    int po=1;
    while(cnt<n){
        bool flag=dfs(po,1);
        int a=0,b=0;
        if(!flag){
            cout<<"Impossible";
            return 0;
        }
        else{
            for(int i = 1;i<=n;i++){
                if(col[i]==1)a++;
                else if(col[i]==2) b++;
            }
            ANS+=min(a,b);
        }
        if(cnt<n){
            po=findnext();
            for(int i = 1;i<=n;i++){
                col[i]=0;
            }
        }
        
    }
    cout<<ANS;
    return 0;
}