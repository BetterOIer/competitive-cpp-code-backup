#include<iostream>
using namespace std;
int n, m;
int a[205];
int road[205][205];
inline void updata(int k){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(road[i][j]>road[i][k]+road[j][k])
	road[i][j]=road[j][i]=road[i][k]+road[j][k];
	return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            road[i][j]=1e9;
        }
    }
    for(int i=0;i<n;i++) road[i][i]=0;
	int vallage_1,village_2,time_val;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&vallage_1,&village_2,&time_val);
		road[vallage_1][village_2]=road[village_2][vallage_1]=time_val;
	}
	int q,now=0;
    scanf("%d",&q);
    for(int i = 1;i<=q;i++){
        scanf("%d%d%d",&vallage_1,&village_2,&time_val);
		while(a[now]<=time_val&&now<n){
			updata(now);
			now++;
		}
        if(a[vallage_1]>time_val||a[village_2]>time_val)puts("-1");
        else {
			if(road[vallage_1][village_2]==1e9)puts("-1");
			else cout<<road[vallage_1][village_2]<<endl;
		}
    }
    return 0;
}