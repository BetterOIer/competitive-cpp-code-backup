#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int to;
    int dis;
    bool operator< (const node x)const{
        return x.dis>dis;
    }
};
vector<pair<int,int>> ro[130];
priority_queue<node> Q;
bool vis[130];
int dis[130];
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        char a,b;
        int c;
        cin>>a>>b>>c;
        ro[(int)a].push_back({b,c});
        ro[(int)b].push_back({a,c});
    }
    for(int i = 1;i<=130;i++) dis[i]=2147483647;
    Q.push((node){'*',0});
    dis[(int)'*']=0;
    while(!Q.empty()){
        node now=Q.top();Q.pop();
        if(vis[now.to]) continue;
        vis[now.to]=true;
        for(auto i:ro[now.to]){
            if(dis[i.first]>dis[now.to]+i.second){
                dis[i.first]=dis[now.to]+i.second;
                Q.push((node){i.first,dis[i.first]});
            }
            
        }
    }
    int who,minn=2147483647;
    for(int i = 'A';i<='Z';i++){
        if(dis[i]<minn){
            minn=dis[i];
            who=i;
        }
    }
    cout<<(char)who<<" "<<minn;
}