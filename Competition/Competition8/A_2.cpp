#include<iostream>
using namespace std;
int n,a[100005],ans,ANS,y;
int compare(int ds){
	int L=0,R=0;
	for(int i=1;i<=n;i++){
		if(ds>a[i]) L++;
		else if(ds<a[i]) R++;
	}
	return min(L,R);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n%2==0){
		for(int i=a[n/2];i<=a[n/2+1];i++){
			int y=compare(i);
			if(y>ans) ANS=i,ans=y;
		}
	}
	else if(n%2==1){
		for(int i=a[n/2];i<=a[n/2+2];i++){
			int y=compare(i);
			if(y>ans) ANS=i,ans=y;
		}
	}
	cout<<ans<<" "<<ANS;
    return 0;
}