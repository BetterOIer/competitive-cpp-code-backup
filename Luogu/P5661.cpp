#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int pri;
    int ti;
    /* bool operator < (const node &w) const{
        return w.ti<w.pri;
    } */
};
deque<node> Q;
int main(){
    int n=read(),opt,t,p;
    long long ans=0;
    for(int i = 1;i<=n;i++){
        cin>>opt>>p>>t;
        if(!opt){
            Q.push_back((node){p,t});
            ans+=p;
        }else{
            bool flag=false;
            int nu=Q.size();
            for(;nu--;){
                node now=Q.front();
                Q.pop_front();
                if(t-now.ti>45){
                    continue;
                }
                if(now.pri>=p&&(!flag)){
                    flag=true;
                    continue;
                }
                Q.push_back(now);
            }
            if(!flag){
                ans+=p;
            }
        }
    }
    cout<<ans;
}