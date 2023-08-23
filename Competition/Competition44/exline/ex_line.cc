#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,maxy,maxx,half,tot=0,cnth=0,cntl=0,cnt;
struct node{
    int y;
    int x;
};
node V[500005];
int geshu[500005];
bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y; 
    return a.x<b.x;
}
int main(){
    int t=read();
    while(t--){
		for(int i = 1;i<=500005;i++){
			geshu[i]=0;
		}
        tot=0;
        cnt=n=read();
		half=n>>1;
        for(int i = 1;i<=n;i++){
			V[i].y=read(),V[i].x=read();
			maxx=max(maxx,V[i].x);
			maxy=max(maxy,V[i].y);
		}
		sort(V+1,V+n+1,cmp);
		cnth=maxy;
		while(tot<half){
			int whi=V[cnt].x;
			tot++;
			geshu[V[cnt--].y]++;
			while(V[cnt].x==whi){
				geshu[V[cnt--].y]++;
				tot++;
			}
		}
		if(tot==half){cout<<2<<endl;continue;}
		while(tot>half){
			tot-=geshu[cnth--];
		}
		if(tot==half){cout<<3<<endl;continue;}
		cout<<4<<endl;
    }
    return 0;
}