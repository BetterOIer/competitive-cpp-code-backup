#include<iostream>
using namespace std;
int a[1001],N,dpf[1001][1001],dps[1001][1001];
int f(int,int);
int s(int,int);
int f(int L,int R){
	if(dpf[L][R]!=-1)return dpf[L][R];
	int ans=0;
	if(L==R) ans=a[L];
	else{
		int p1=a[L]+s(L+1,R);
		int p2=a[R]+s(L,R-1);
		ans= max(p1,p2);
	}
	dpf[L][R]=ans;
	return ans;
}
int s(int L,int R){
	if(dps[L][R]!=-1) return dps[L][R];
	int ans=0;
	if(L!=R){
		int p1= f(L+1,R);
		int p2= f(L,R-1);
		ans= min(p1,p2);
	}
	dps[L][R]=ans;
	return ans;
}
void win(){
    for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			dpf[i][j]=-1;
			dps[i][j]=-1;
		}
	}
    int ans1=f(1,N);
    int ans2=s(1,N);
    printf("%d %d",ans1,ans2);
}
int main(){
    cin>>N;
    for(int i = 1;i<=N;i++) scanf("%d",a+i);
    win();
    return 0;
}