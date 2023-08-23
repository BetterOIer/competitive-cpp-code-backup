#include<iostream>
#include<queue>
using namespace std;
struct node{
    int start,end;
    int data=-1;
};
queue <node> Q;
int n;
inline int read(){
   register int s=0,w=1;
   register char ch=getchar(); 
   while(ch<'0'||ch>'9'){if(ch=='-'){w=-1,ch=getchar();}}
   while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
   return s*w;
}
int main(){
    freopen("fruit.in","r",stdin);
    freopen("fruit.out","w",stdout);
    n=read();
    node xz,zq;
    int flag=-1,now;
    now=read();
    xz.start=1;
    xz.data=now;
    flag=now;
    for(int i = 2;i<=n;i++){
        now=read();
        if(now!=flag){
            swap(xz,zq);
            xz.start=i;
            xz.data=now;
            zq.end=i-1;
            Q.push(zq);
        }
        flag=now;
    }
    xz.end=n;
    Q.push(xz);
    node before;
    while(!Q.empty()){
        before.data=-1;
        int len=Q.size();
        for(int i = 1;i<=len;i++){
            node now=Q.front();Q.pop();
            if(now.data!=before.data) printf("%d ",now.start++);
            if(now.start<=now.end){
                Q.push(now);
            }
            swap(now,before);
        }
        puts("");
    }
}