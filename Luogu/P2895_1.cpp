#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[310][310];
int lx[310][310];
int zg[310][310];
int dir[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
struct pcwNbest{
    int t;
    int x,y;
};
queue <pcwNbest> Q;
void print(){
    for(int i = 0;i<=10;i++){
        for(int w = 0;w<=10;++w){
            cout<<map[i][w]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int n,now_t=1,x,y,t;
    memset(lx,127,sizeof(lx));
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>x>>y>>t;
        if(x==0&&y==0&&t==0){
            cout<<-1;
            return 0;
        }
        for(int w = 0;w<=4;w++){
            if(y+dir[w][0]>=0&&x+dir[w][1]>=0&&lx[y+dir[w][0]][x+dir[w][1]]==2139062143){
                lx[y+dir[w][0]][x+dir[w][1]]=t;
                map[y+dir[w][0]][x+dir[w][1]]=1;
            }
        }
    }
    Q.push((pcwNbest){0, 0, 0});
    zg[0][0]=1;
    while(!Q.empty()){
        pcwNbest fa = Q.front();
        Q.pop();
        now_t=fa.t+1;
        
        for(int i = 1;i<=4;i++){
            if(fa.y+dir[i][0]>=0&&fa.x+dir[i][1]>=0){
                if(map[fa.y+dir[i][0]][fa.x+dir[i][1]]==0){
                    cout<<now_t;
                    return 0;
                }else if(map[fa.y+dir[i][0]][fa.x+dir[i][1]]==1&&lx[fa.y+dir[i][0]][fa.x+dir[i][1]]>now_t&&zg[fa.y+dir[i][0]][fa.x+dir[i][1]]==0){
                    Q.push((pcwNbest){now_t,fa.x+dir[i][1],fa.y+dir[i][0]});
                    zg[fa.y+dir[i][0]][fa.x+dir[i][1]]=1;
                }
            }
        }
    }
    cout<<"-1";
    return 0;
}
