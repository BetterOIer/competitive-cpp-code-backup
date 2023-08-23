#include<bits/stdc++.h>
#define big 9999999
#define bigger 99999999
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dt[103][103];
map<string,int> M;
map<int,string> R;
int tot=0;
string who,zmc="ZMC";
bool check(int i){
	int l1=R[i].length(),l2=who.length(),L;
	L=min(l1,l2);
	for(int j = 0;j<=L-1;j++){
		if(R[i][j]<who[j])return true;
		if(R[i][j]>who[j])return false;
	}
	if(l1>l2) return false;
	else return true;
}
int main(){
	for(int i =1;i<=100;i++){
		for(int j =1;j<=100;j++) dt[i][j]=bigger;
		dt[i][i]=0;
	}
	int m=read(),rea=0,dep=0;
	string s1,s2;
	for(int i = 1;i<=m;i++){
		cin>>s1>>s2>>rea;
		if(M.find(s1)==M.end())	{
			M[s1]=++tot;
			R[tot]=s1;
		}
		if(M.find(s2)==M.end()){
			M[s2]=++tot;
			R[tot]=s2;
		}
		if(rea==-1) dt[M[s1]][M[s2]]=big;
		else if(rea==-2) dt[M[s1]][M[s2]]=bigger;
		else dt[M[s1]][M[s2]]=rea;
	}
	for(int k = 1;k<=tot;k++){
		for(int i = 1;i<=tot;i++){
			for(int j = 1;j<=tot;j++){
				if(i==k||j==k||i==j)continue;
				if(dt[i][j]<big&&dt[i][k]<big&&dt[k][j]<big){
					if(dt[i][j]>dt[i][k]+dt[k][j]){
						dt[i][j]=dt[i][k]+dt[k][j];
					}
				}
				else{
					if(dt[i][j]==big&&dt[i][k]<big&&dt[k][j]<big) dt[i][j]=dt[i][k]+dt[k][j];
					if(dt[i][j]==bigger&&((dt[i][k]==big&&dt[k][j]<big)||(dt[i][k]<big&&dt[k][j]==big)||(dt[i][k]==big&&dt[k][j]==big))) dt[i][j]=big;
					if(dt[i][j]==bigger&&dt[i][k]<big&&dt[k][j]<big) dt[i][j]=dt[i][k]+dt[k][j];
				}
			}
		}
	}
	for(int i = 1;i<=tot;i++){
		if(dt[i][M[zmc]]>dep){
			who=R[i];
			dep=dt[i][M[zmc]];
		}else if(dt[i][M[zmc]]==dep&&check(i)){
			who=R[i];
		}
	}
	cout<<who<<" ";
	if(dep==big)cout<<-1;
	else if(dep==bigger)cout<<-2;
	else cout<<dep;
	fclose(stdin);
	fclose(stdout);
}
