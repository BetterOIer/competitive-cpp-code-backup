#include<iostream>
#include<vector>
using namespace std;
vector <int> work[100010];
int vis[100010],ans=0;
int dfs(int x){
    if(vis[x]) return vis[x];
    for(int i = 1;i<=work[x].size()-1;i++){
        vis[x]=max(vis[x],dfs(work[x][i]));
    }
    vis[x]+=work[x][0];
    return vis[x];
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int a1,cost;
        cin>>a1>>cost>>a1;
        work[i].push_back(cost);
        while(a1!=0){
            work[i].push_back(a1);
            cin>>a1;
        }
    }
    for(int i = 1;i<=n;i++){
        ans=max(ans,dfs(i));
    }
    cout<<ans;
}