#include<iostream>
using namespace std;
short int n,f[5000][5000],len;
void gjj(int k){
	for(int i=1;i<=len;i++)	f[k][i]=f[k-1][i]+f[k-2][i];
	for(int i=1;i<=len;i++){
		if(f[k][i]>=10){
			f[k][i+1]+=f[k][i]/10;
			f[k][i]%=10;
			if(f[k][len+1]>0) len++;
		}
	}
}
int main(){
	cin>>n;
	len=1;
	f[1][1]=1;f[2][1]=2;
	for(int i=3;i<=n;i++) gjj(i);
	for(int i=len;i>=1;i--) cout<<f[n][i];
	return 0; 
}