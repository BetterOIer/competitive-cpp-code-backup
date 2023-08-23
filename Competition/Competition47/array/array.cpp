#include<iostream>
#include<queue>
using namespace std;
int n,b[5010],b1[10];
struct node{
    int an[10]={0,0,0,0,0,0,0,0,0,0};
};
queue<node>Q;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int ans;
void out(node now){
    for(int i = 1;i<=n;i++){
        cout<<b1[i]<<" ";
    }
    cout<<endl;
}
bool check(node now){
    for(int i = 1;i<=n;i++){
        if(b[i]!=now.an[i])return false;
    }
    return true;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		b1[i]=b[i]=read();
		ans+=b[i];
	}	
	if(ans%2==1||n==1)cout<<0<<endl; 
	else if(n==2){
		if(b[1]!=b[2]) cout<<0<<endl;
		else cout<<1<<endl;
    }
    else{
        ans=0;
        node sta;
        Q.push(sta);
        while(Q.size()){
            node now=Q.front();Q.pop();
            if(check(now)){
                ans=(ans+1)%998244353;
                continue;
            }
            for(int i = 1;i<=n-1;i++){
                for(int j=i+1;j<=n;j++){
                    now.an[i]++;
                    now.an[j]++;
                    if(now.an[i]<=b1[i]&&now.an[j]<=b1[j]) Q.push(now);
                    now.an[i]--;
                    now.an[j]--;
                }
            }
        }
        cout<<ans<<endl;
    }
}