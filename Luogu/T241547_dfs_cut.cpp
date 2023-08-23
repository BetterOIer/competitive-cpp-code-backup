#include<iostream>
#include<cmath>
using namespace std;
int a[105][105], zg[105][105], dirx[4]={1,-1,0,0}, diry[4]={0,0,1,-1},best_dist, n,m,W,p,x,dx,o,zyxx,zyxy,csx,csy,zyw=0,cs=0;
long long ans=1000000000,sy=0;
struct cswz{
    int x,y;
}cspo[5];
void dfs(){
    if(a[zyxy][zyxx]==2){
        ans= ans<sy? ans:sy;
        return ;
    }
    zg[zyxy][zyxx]=1;
    for(int i = 0;i<=3;i++){
        if(!zg[zyxy+diry[i]][zyxx+dirx[i]]&&zyxy+diry[i]>0&&zyxy+diry[i]<=n&&zyxx+dirx[i]>0&&zyxx+dirx[i]<=m&&sy<ans){
            zyxy+=diry[i],zyxx+=dirx[i];
            if(a[zyxy][zyxx]==0||a[zyxy][zyxx]==2){
                if(sy<=p){ sy+=o; dfs(); sy-=o;}
                else{ sy+=2*o; dfs(); sy-=(2*o);}
            }else if(a[zyxy][zyxx]==1){
                if(sy<=p){ sy+=(x+o); dfs(); sy-=(x+o);}
                else {sy+=(x+dx+2*o); dfs(); sy-=(x+dx+2*o);}
            }
            zyxy-=diry[i],zyxx-=dirx[i];
        }
    }
    zg[zyxy][zyxx]=0;
}
int main(){
    cin>>n>>m>>W>>p>>x>>dx>>o;
    int k=0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='.')a[i][j]=0;
            else if(c=='#'){a[i][j]=1;zyw++;}
            else if(c=='$'){
                a[i][j]=2;cs++;
                cspo[++k].y=i,cspo[k].x=j;
            }
            else if(c=='@'){a[i][j]=0;zyxx=j;zyxy=i;}
        }
    }
    if(cs==0){
        cout<<zyw<<endl<<"ZYX is clown!!!YQT gdpl!!!";
        return 0;
    }else{
        for(int i = 1;i<=k;i++){
            int d=(abs(cspo[i].y-zyxy)+abs(cspo[i].x-zyxx)-1)*(x+o)+o;
            if(d<=p){
                best_dist=d;
            }
            else{
                best_dist=ceil(1.0*p/(x+o))*(x+o)+(abs(cspo[i].y-zyxy)+abs(cspo[i].x-zyxx)-ceil(1.0*p/(x+o))-1)*(x+dx+2*o)+2*o;
            }
            ans=best_dist<ans? best_dist:ans;
        }
    }
    dfs();
    if(ans>W) cout<<ans<<endl<<"ZYX is clown!!!YQT gdpl!!!";
    else cout<<ans<<endl<<"SINB YQT!!!";
    return 0;
}