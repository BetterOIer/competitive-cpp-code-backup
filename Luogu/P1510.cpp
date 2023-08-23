#include<iostream>
using namespace std;
long long val[100000],dp[1000000],tl[100000],all=0;
int main(){
    int v,n,c;
    cin>>v>>n>>c;
    for(int i = 1;i<=n;i++) {
        cin>>val[i]>>tl[i];
        all+=val[i];
    }
    if(all<v){cout<<"Impossible";return 0;}
    for(int i = 1;i<=n;i++){
        for(int w = c;w>=tl[i];w--){
            dp[w]=max(dp[w],dp[w-tl[i]]+val[i]);
        }
    }
    for(int i=0;i<=v;i++){
		if(dp[i]>=v){
			cout<<c-i<<endl;
			return 0;
		}
	}
	cout<<"Impossible"<<endl;
    return 0;
}