#include<iostream>
//#include<cstdio>
#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
using namespace std;
//int a[];
struct milk{
    int cost,mol;
}a[5010];
bool comp(milk a,milk b){
    return a.cost<b.cost;
}
int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i = 0;i<=m-1;i++){
        cin>>a[i].cost>>a[i].mol;
    }
    sort(a,a+m,comp);
    int k = 0;
    for(int i=0;i<=m-1;i++){
		if(a[i].mol<=n){
			ans+=a[i].mol*a[i].cost;
			n-=a[i].mol;
		}
		else{
			ans+=n*a[i].cost;
			break;
		}
	}
    cout<<ans;
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 