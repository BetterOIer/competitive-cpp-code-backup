#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,x,y;
int be[10005];
int find(int x){
    return x==be[x]? x:be[x]=find(be[x]);
}
void join(int x,int y){
    be[find(x)]=find(y);
}
int main(){
    n=read(),m=read();    
    for(int i = 1;i<=n;i++)be[i]=i;
    for(int i = 1;i<=m;i++){
        if(read()==1){
            join(read(),read());
        }else{
            if(find(read())==find(read()))cout<<"Y\n";
            else cout<<"N\n";
        }
    }
    return 0;
}