#include<iostream>
#include<stack>
#include <cctype>
#include <cmath>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <array>
#define int long long
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
map<pair<unsigned long long ,unsigned long long>,unsigned long long> Q;
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
signed main(){
    long long n=read(),x,y,hi;
    unsigned long long base,ans=0;
    for(int i = 1;i<=n;i++){
        x=read(),y=read(),hi=read();
        if(Q.find({x,y})==Q.end()){
            base=0;
            Q[{x,y}]=hi;
        }
        else{
            base=Q[{x,y}];
            Q[{x,y}]+=hi;
        }
        for(int w = 0;w<4;w++){
            if(Q.find({x+dirx[w],y+diry[w]})==Q.end()){
                ans+=hi;
            }else{
                if(Q[{x+dirx[w],y+diry[w]}]>=hi+base) ans-=hi;
                else if(Q[{x+dirx[w],y+diry[w]}]<=base){
                    ans+=hi;
                }
                else{
                    ans-=(Q[{x+dirx[w],y+diry[w]}]-base);
                    ans+=(hi+base-Q[{x+dirx[w],y+diry[w]}]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
