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
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int x,k,n,q,cnt,now=1,stas[1<<10];
long long val[10],sum=0;
struct Matrix{
	long long val[71][71];
	Matrix(){
        for(int i=1;i<=70;i++){
            for(int j=1;j<=70;j++)val[i][j]=1e18;
            val[i][i]=0;
        }
    }
	Matrix operator * (const Matrix &a) const{
		Matrix tmp;
		for(int i=1;i<=cnt;i++)tmp.val[i][i]=1e18;
		for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++)for(int k=1;k<=cnt;k++)tmp.val[i][j]=min(tmp.val[i][j],val[i][k]+a.val[k][j]);
		return tmp;
	}
	Matrix operator ^ (const int &x) 
	{
		if(!x) return Matrix();
		Matrix tmp,tmp1;int times=x;
		for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++) tmp1.val[i][j]=val[i][j];
		while(times) {if(times&1) tmp=tmp*tmp1;times>>=1;tmp1=tmp1*tmp1;}
		return tmp;
	}
}m;
struct Stm{
    int place;long long val;
}stm[30];
bool operator < (const Stm &a,const Stm &b){
    return a.place<b.place;
}
bool cal(int tmp){
	int many=0;
	for(int i=1;i<=8;i++) if(tmp&(1<<(i-1))) many++;
	return many==x;
}

int main(){
	x=read(),k=read(),n=read(),q=read();
	for(int i=0;i<=(1<<k)-1;i++) if(cal(i)) stas[i]=++cnt;
	for(int i=1;i<=k;i++) val[i]=read();
	for(int i=1;i<=q;i++) stm[i].place=read(),stm[i].val=read();
	sort(stm+1,stm+q+1);
	for(int i=1;i<=cnt;i++) m.val[i][i]=1e18;
	for(int i=1;i<=(1<<k)-1;i++){
		if(!stas[i]) continue;
		if(i&1){
            for(int j=1;j<=k;j++){
                if(!((1<<j)&i)) m.val[stas[i]][stas[((1<<j)|i)>>1]]=val[j];
            }
        }
		else m.val[stas[i]][stas[i>>1]]=0;
	}
	int now=1;long long sum=0;Matrix ans;
	for(int i=1;i<=q;i++)
	{
		if(stm[i].place>n-x) {sum+=stm[i].val;continue;}
		ans=ans*(m^(stm[i].place-now)),now=stm[i].place;
		for(int j=1;j<=(1<<k)-1;j+=2)
			if(stas[j])
				for(int k=1;k<=cnt;k++)
					ans.val[k][stas[j]]+=stm[i].val;
	}
	ans=ans*(m^(n-x+1-now));
	return printf("%lld",ans.val[1][1]+sum),0;
}