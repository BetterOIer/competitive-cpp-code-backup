/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,q;
struct EDGE{
    int x1;
    int x2;
    int val;
    int idx;
};
int fa[1000005];
bool operator < (EDGE a, EDGE b){return a.val<b.val;}
bool operator > (EDGE a, EDGE b){return a.val>b.val;}
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void join(int x,int y){
    fa[find(x)]=fa[find(y)];
}
vector<EDGE>edge,cent;
int main(){
    n=read(),m=read();
    for(int i = 1,x1,x2,val;i<=m;i++){
        x1=read(),x2=read(),val=read();
        edge.push_back((EDGE){x1,x2,val,i});
    }
    cent=edge;
    sort(cent.begin(),cent.end());
    q=read();
    for(int i = 1,k;i<=q;i++){
        for(int i = 1;i<=n;i++){
            fa[i]=i;
        }
        vector<EDGE> req;
        k=read();
        for(int j = 1,idx;j<=k;j++){
            idx=read()-1;
            req.push_back(edge[idx]);
        }
        sort(req.begin(),req.end());
        int point=0;
        bool flag=true;
        for(EDGE i:cent){
            while(point<req.size()&&i.val==req[point].val){
                if(find(req[point].x1)==find(req[point].x2)){
                    flag=false;
                    goto concl;
                }else{
                    join(req[point].x1,req[point].x2);
                }
                point++;
            }
            if(find(i.x1)!=find(i.x2)){
                join(i.x1,i.x2);
            }
        }
        concl:
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}