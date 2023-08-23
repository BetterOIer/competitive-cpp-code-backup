#include<iostream>
#include<cstring>
using namespace std;
int m,tot,a,n,e;
char sb[200005];
signed main(){
	cin>>m;
	while(m--){
		memset(sb,0,sizeof(sb));
        tot=0;
		cin>>n>>a>>e;
		if(e>n*2){
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=1;i<=n*2;i++){
			cin>>sb[i];
			if(sb[i]=='A') tot++;
		}
		if(abs(tot-a)%2!=e%2){
			cout<<"-1"<<endl;
			continue;
		}
		int cnt=(e-abs(tot-a))/2;
		int cntl=cnt;
		int zcnt=tot-a;
		for(int i=1;i<=n*2;i++){
			if(sb[i]=='A' && cnt>0){
				sb[i]='B';
				cnt--;
			}
			else if(sb[i]=='B' && cntl>0){
				sb[i]='A';
				cntl--;
			}
			else if(zcnt>0 && sb[i]=='A'){
				sb[i]='B';
				zcnt--;
			}
			else if(zcnt<0 && sb[i]=='B'){
				sb[i]='A';
				zcnt++;
			}
			if(!cnt && !cntl && !zcnt) break;
		}
		if(cnt!=0 || cntl!=0 || zcnt!=0){
			cout<<"-1"<<endl;
		}
		else{
			for(int i=1;i<=n*2;i++){
				cout<<sb[i];
			}
			cout<<endl;
		}
	}
	return 0;
}