#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int to;
    int open;
};
struct Qnode{
    int po;
    int tim;
};
vector<node>city[1005];
queue<Qnode>Q;
int main(){
    freopen("plan.in","r",stdin);
    freopen("plan.out","w",stdout);
    int n=read(),m=read(),q=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read();
        v=read();
        city[u].push_back((node){v,i});
        city[v].push_back((node){u,i});
    }
    for(int i = 1,l,r,s,t;i<=q;i++){
        l=read(),r=read(),s=read(),t=read();
        Q.push((Qnode){s,l-1});
        bool flag=false;
        while(Q.size()){
            Qnode now=Q.front();Q.pop();
            if(now.tim>r)continue;
            if(now.po==t){
                cout<<"Yes"<<endl;
                while(Q.size())Q.pop();
                flag=true;
                break;
            }
            for(node i:city[now.po]){
                if(i.open==now.tim+1){
                    Q.push((Qnode){i.to,now.tim+1});
                }
            }
            Q.push((Qnode){now.po,now.tim+1});
        }
        if(!flag)cout<<"No"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}