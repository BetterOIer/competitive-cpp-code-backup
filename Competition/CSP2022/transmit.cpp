#include<vector>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
inline int read(){
    char c=getchar();int x=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m,q;
int  score[200005]; 
bool v[200005];
vector<int >ro[200005];
int dis[200005];
struct node{
    int po;
    int val;
    bool operator < (const node &w)const{
        return w.val < val;
    }
};
priority_queue<node>Q;
long long ans=0;
void Dji(int s){
	memset(v,0,sizeof v);
	memset(dis,0x3f3f3f,sizeof dis);
    dis[s]=0;
    Q.push((node){s,4});
    v[s]=true;
    while(Q.size()){
        node now=Q.top();Q.pop();
        v[now.po]=true;
        for(int i:ro[now.po]){
            if(v[i])continue;
            if(dis[i]>now.val+score[i]){
                dis[i]=now.val+score[i];
                Q.push((node){i,now.val+score[i]});
            }
        }
    }
}
int main(){
    freopen("transmit.in","r",stdin);
    freopen("transmit.out","w",stdout);
    n=read(),q=read(),m=read();
    for(int i = 1;i<=n;i++)score[i]=read();
    for(int i = 1,x,y;i<n;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
    }
    for(int i = 1,x,y;i<=q;i++){
        x=read(),y=read();
        Dji(x);
        cout<<dis[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}