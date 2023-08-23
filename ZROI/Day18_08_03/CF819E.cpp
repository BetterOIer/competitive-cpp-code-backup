/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
vector<vector<int> >ans;
int main(){
    n=read();
	if(n&1){
		ans.push_back({1,2,3});ans.push_back({1,2,3});
		for(int i=5;i<=n;i+=2){
			int s=i-1,t=i;
			ans.push_back({s,1,t});ans.push_back({s,1,t});
			for(int j=3;j<i;j+=2) ans.push_back({s,j-1,t,j}),ans.push_back({s,j-1,t,j});
		}
	}
	else{
		ans.push_back({1,2,3});ans.push_back({1,2,4});ans.push_back({3,4,1});ans.push_back({3,4,2});
		for(int i=6;i<=n;i+=2){
			int s=i-1,t=i;
			ans.push_back({s,1,t});ans.push_back({s,2,t});ans.push_back({s,1,t,2});
			for(int j=4;j<i;j+=2) ans.push_back({s,j-1,t,j}),ans.push_back({s,j-1,t,j});
		}
	}
	cout<<ans.size()<<endl;
	for(vector<int> i:ans){
        cout<<i.size();
        for(int j:i) cout<<" "<<j;
        cout<<endl;
    }
    return 0;
}