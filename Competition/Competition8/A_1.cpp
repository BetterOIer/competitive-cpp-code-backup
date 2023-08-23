#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans,q;
int js(int x){
	int ansx=0,ansd=0;
	for(int i=1;i<=n;i++){
		if(x>a[i]){
			ansx++;
		}
		else if(x<a[i])ansd++;
	}
	return min(ansx,ansd);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==0){
		for(int i=a[n/2];i<=a[n/2+1];i++){
			int y=js(i);
			if(y>ans){
				q=i;
				ans=y;
			}
		}
	}
	else{
		for(int i=a[n/2];i<=a[n/2+2];i++){
			int y=js(i);
			if(y>ans){
				q=i;
				ans=y;
			}
		}
	}
	cout<<ans<<" "<<q;
}