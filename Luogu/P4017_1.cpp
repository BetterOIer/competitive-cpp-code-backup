#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int ru[5005],chu[5005],dis[5005];
vector <int> rela[5003];
queue <int> Q;
unsigned long long ans=0;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int x1,x2;
        cin>>x1>>x2;
        ru[x2]++,chu[x1]++;
        rela[x1].push_back(x2); 
    }
    for(int i = 1;i<=n;i++){
        if(!ru[i]){
        	Q.push(i);
        	dis[i]=1;
		}
    }
    while(!Q.empty()){
    	int dq =Q.front();
    	Q.pop();
    	int len=rela[dq].size();
    	for(int i = 0;i<=len-1;i++){
    		ru[rela[dq][i]]--;
    		dis[rela[dq][i]]=(dis[rela[dq][i]]+dis[dq])%80112002;
			if(ru[rela[dq][i]]==0) Q.push(rela[dq][i]);
		}
	}
	for(int i = 1;i<=n;i++){
        if(!chu[i]) ans=(ans+dis[i])%80112002;
    }
    cout<<ans;
    return 0;
}