#include<iostream>
using namespace std;
long long t;
long long n,m,x,y;
long long ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>x>>y;
		long long l1=n/x,r1=m/y,l2=m/x,r2=n/y;
        long long ans=0,ans1=0,ans2=0,ans3=0,ans4=0;
		if(x==y) ans=l1*r1*x*y;
		else if(x>y){
			ans1=l1*r1*x*y;
			ans1+=((n-l1*x)/y)*l2*x*y;
			ans2=l2*r2*x*y;
			ans2+=((m-l2*x)/y)*l1*x*y;
		}
		else{
			ans3=l1*r1*x*y;
			ans3+=((m-r1*y)/x)*r2*x*y;
			ans4=l2*r2*x*y;
			ans4+=((n-r2*y)/x)*r1*x*y;
		}
		ans=max(ans,max(max(ans1,ans2),max(ans3,ans4)));
		cout<<ans<<endl;
	}
	return 0;
}