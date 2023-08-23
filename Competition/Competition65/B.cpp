/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<stack>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
bool used[3]={1,1,1};
int T(char c){
    if(c=='B')return 1;
    if(c=='W')return 2;
    if(c=='R')return 0;
    return -1;
}
int n;
string s;
stack<int>stk;
int main(){
    stk.push(0);
    stk.push(1);
    stk.push(2);
    n=read();
    cin>>s;
    int ans=0;
    for(int i = 0;i<n;i++){
        int req = T(s[i]);
        if(used[req]){
            while(stk.top()!=req)used[stk.top()]=false,stk.pop(),ans++;
        }else{
            while(stk.top()>req)used[stk.top()]=false,stk.pop(),ans++;
            used[req]=true,stk.push(req),ans++;
        }
    }
    cout<<ans;
    return 0;
}