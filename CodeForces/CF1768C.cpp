/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 最最好的，与最最痛苦的，是一样的。 --文学与少女
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long n, k, a[3000005], p[3000005], q[3000005];
vector<long long> b[3000005];
int main(){
	long long t=read();
	while(t--){
		n=read();
        queue<long long> Q,P;
        bool can=true;
        for(long long i=1;i<=n;i++){
            a[i]=read();
            b[a[i]].push_back(i);
            if(b[a[i]].size()>2){
                can=false;
            }
        }
        if(!can){
            cout << "NO\n";
            goto nex;
        }
        for(long long i=n;i>=1;i--){
            if(b[i].size() == 1){
                p[b[i][0]]=q[b[i][0]]=i;
            }else if(b[i].size() == 2){
                p[b[i][0]]=q[b[i][1]]=i;
                P.push(b[i][1]);
                Q.push(b[i][0]);
            }else{
                if(!Q.size()){
                    cout<<"NO\n";
                    goto nex;
                }
                long long front=Q.front();Q.pop();
                q[front]=i;
                front=P.front();P.pop();
                p[front]=i;
            }
        }
        cout<<"YES\n";
        for(long long i=1;i<=n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        for(long long i=1;i<=n;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
        nex:
        for(long long i=1;i<=n;i++) b[i].clear(),p[i]=q[i]=0;
	}
	return 0;
}