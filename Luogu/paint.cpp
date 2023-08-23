/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int id;
    int col;
}hang[100005],lie[100005];
int main(){
    int T=read();
    while(T--){
        int n=read(),m=read(),q=read();
        for(int i = 1,opt,x,c;i<=q;i++){
            opt=read(),x=read(),c=read();
            if(opt==0)hang[x].col=c,hang[x].id=i;
            if(opt==1)lie[x].col=c,lie[x].id=i;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cout<<(hang[i].id>lie[j].id? hang[i].col:lie[j].col)<<" ";
            }
            cout<<endl;
        }
        memset(hang,0,sizeof hang);
        memset(lie,0,sizeof lie);
    }
}