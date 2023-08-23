#include<bits/stdc++.h>
#define sec 985
using namespace std;
int m,n,dt[101][101],ti;
bool vis[101][101]={true},cango=false;
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
long long ANS=9223372036854775807,ans=0;
void dfs(int y,int x,int spec=0){
    if(ans>=ANS||clock()-ti>sec) return ;
    if(y==m&&x==m){
        ANS=min(ANS,ans);
        cango=true;
        return ;
    }
    for(int i = 0;i<=3&&clock()-ti<sec;i++){
        if(!vis[y+diry[i]][x+dirx[i]]&&y+diry[i]>=1&&y+diry[i]<=m&&x+dirx[i]>=1&&x+dirx[i]<=m){
            vis[y+diry[i]][x+dirx[i]]=true;
            if(dt[y+diry[i]][x+dirx[i]]==dt[y][x]){
                dfs(y+diry[i],x+dirx[i]);
            }else if(dt[y+diry[i]][x+dirx[i]]!=dt[y][x]){
                ans+=1;
                dfs(y+diry[i],x+dirx[i]);
                ans-=1;
            }else if(dt[y+diry[i]][x+dirx[i]]==0){
                if(!spec){
                    ans+=2;
                    dt[y+diry[i]][x+dirx[i]]=dt[y][x];
                    dfs(y+diry[i],x+dirx[i],1);
                    dt[y+diry[i]][x+dirx[i]]=0;
                    ans-=2;
                }
            }
            vis[y+diry[i]][x+dirx[i]]=false;
        }
    }
}
int main(){
    ti=clock();
    int c,x,y;
    cin>>m>>n;
    for(int i = 1;i<=n;i++){
        cin>>y>>x>>c;
        dt[y][x]=2-c;
    }
    dfs(1,1);
    if(cango)cout<<ANS;
    else cout<<-1;
    cout<<clock();
    return 0;
}