/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https:
* FileStation: https:
* OnlineJudge: http:
=================================================*/
#include <iostream>
#include <cmath>
using namespace std;
const int N=1e6+10,M=1e5+10;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,C[N<<1],c[N<<1],top,typ[M],k[M],hds;
bool used[M];
string s;
int lowbit(int x){
    return x&-x;
}
void add(int x,int y,int t[]){
	for(x+=N;x<=2e6+10;x+=lowbit(x))
		t[x]+=y;
}
int sum(int x,int t[]){
	int ans=0;
	for(x+=N;x;x-=lowbit(x))
		ans+=t[x];
	return ans;
}
int main(){
	n=read();
	for(int x,y,z,i=1;i<=n;i++){
		cin>>s;
		if(s=="Add"){
			x=read(),y=read(),z=read();
			if(!x){
				if(y>z)hds++,typ[++top]=3;
				else typ[++top]=0;
			}
			if(x>0){
				k[++top]=floor((z*1.0-y)/x);
				if(k[top]>1e6)typ[top]=0;
				else if(k[top]<-1e6) hds++,typ[top]=3;
				else typ[top]=1,add(k[top],1,C);
			}
			if(x<0){
				k[++top]=ceil((z*1.0-y)/x);
				if(k[top]<-1e6)typ[top]=0;
				else if(k[top]>1e6) hds++,typ[top]=3;
				else typ[top]=2,add(k[top],1,c);
			}
		}
		if(s=="Query"){
			x=read();
			cout<<sum(x-1,C)+(sum(1e6,c)-sum(x,c))+hds<<endl;
		}
		if(s=="Del"){
			x=read();
			if(used[x])continue;
			used[x]=true;
			if(typ[x]==3)hds--;
			if(typ[x]==1)add(k[x],-1,C);
			if(typ[x]==2)add(k[x],-1,c);
		}
    }
	return 0;
}