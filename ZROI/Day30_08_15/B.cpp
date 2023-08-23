/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
int n,ans;
char g[10005][10005];
int main(){
    std::ios::sync_with_stdio(false),
	std::cin.tie(0), std::cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;ans=2;
        for(int i = 1;i<=n;i++){
            cin>>(g[i]+1);
        }
        if(n!=1){for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i!=j&&g[i][j]=='0'){
                    break;
                }else if(j==n){
                    ans=1;
                }
            }
        }}
        else {ans=0;}
        cout<<ans<<"\n";
    }
    return 0;
}