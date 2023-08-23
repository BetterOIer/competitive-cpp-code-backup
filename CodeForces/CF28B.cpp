#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,fa[105],a[105],d[105];
int find(int a){return fa[a]==a? a:fa[a]=find(fa[a]);}
void join(int x,int y){
    if(find(x)!=find(y)){
        fa[find(x)]=find(y);
    }
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
	    a[i]=read();
	    fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		d[i]=read();
		if(i>d[i]) join(i,i-d[i]);
		if(i+d[i]<=n) join(i,i+d[i]);
	}
	for(int i=1;i<=n;i++){
		if(find(i)!=find(a[i])){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}