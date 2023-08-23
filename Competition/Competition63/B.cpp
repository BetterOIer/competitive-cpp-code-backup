/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,x_size,y_size,tot=0,used=0;
long long ans=0;
struct node{
    int a1;
    int a2;
    int val;
}Edge[25];
int be[5005],del=0;
int bel=0;
bool cmp(node a,node b){
    return a.val>b.val;
}
int find(int x){
    return be[x];
}
void join(int x,int y){
    be[find(x)]=find(y);
}
void Kruskal(){
    sort(Edge+1,Edge+n,cmp);
    for(int i = 1;i<n;i++){
        int f1=find(Edge[i].a1),f2=find(Edge[i].a2);
        if(f1>f2)swap(f1,f2);
        if(f1==f2){
            continue;
        }else if(f1==1&&f2==2){
            del+=Edge[i].val;
        }else if(f1==0&&f2){
            if(!bel){
                bel=f2;
            }else{
                if(bel!=f2){
                    del+=Edge[i].val;
                }
            }
        }
    }
}
int main(){
    n=read();
    x_size=read();
    /* for(int i = 1;i<=n;i++){
        be[i]=i;
    } */
    for(int i = 1,x;i<=x_size;i++){
        x=read();
        be[x]=1;
    }
    y_size=read();
    for(int i = 1,y;i<=y_size;i++){
        y=read();
        be[y]=2;
    }
    for(int i = 1;i<n;i++){
        Edge[i].a1=read(),Edge[i].a2=read(),Edge[i].val=read();
    }
    Kruskal();
    cout<<del;
    return 0;
}