//About 20pts
#include<iostream>
#include<queue>
#include<set>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
string os,gs;
int len,origin,goal;
struct node{
    string s;
    int step;
};
queue<node>Q;
set<string>mint;
int trans(string s){
    int ans=0;
    for(int i = 0;i<len;i++){
        ans+=((s[i]-'0')<<(len-i-1));
    }
    return ans;
}
void solve(){
    while(Q.size())Q.pop();
    mint.clear();
    Q.push((node){os,0});
    while(Q.size()){
        node now=Q.front();Q.pop();
        if(mint.find(now.s)!=mint.end())continue;
        if(now.s==gs){
            cout<<now.step<<endl;
            return;
        }
        mint.insert(now.s);
        string cnt=now.s;
        for(int i = 0;i<len;i++){
            cnt[i]='1'-cnt[i]+'0';
        }
        for(int i = 0;i<len;i++){
            if(cnt[i]=='0'){
                cnt[i]='1';
                Q.push((node){cnt,now.step+1});
                cnt[i]='0';
            }
        }
    }
}
int main(){
    freopen("flip.in","r",stdin);
    freopen("flip.out","w",stdout);
    int T=read();
    while(T--){
        len=read();
        cin>>os>>gs;
        origin= trans(os),goal=trans(gs);
        if(origin==goal){
            cout<<0<<endl;
            continue;
        }
        if(origin==0){
            cout<<-1<<endl;
            continue;
        }
        solve();
    }
    return 0;
}