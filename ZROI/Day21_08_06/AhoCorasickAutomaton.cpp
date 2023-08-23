/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int ch[1000005][26],idx,n;
int nex[1000005],cnt[1000005];
string s,pat;
void build_Trie(){
    int pos=0;
    for(int i = 0;pat[i];i++){
        int j = pat[i]-'a';
        if(!ch[pos][j])ch[pos][j]=++idx;
        pos=ch[pos][j];
    }
    ++cnt[pos];
}
void build_AC(){
    queue<int>q;
    for(int i = 0;i<26;i++) if(ch[0][i])q.push(ch[0][i]);
    while(q.size()){
        int now = q.front();q.pop();
        for(int i = 0 ;i<26;i++){
            int to = ch[now][i];
            if(to)nex[to]=ch[nex[now]][i],q.push(to);
            else ch[now][i]=ch[nex[now]][i];
        }
    }
}
int query(){
    int ans=0;
    for(int k = 0,i=0;s[k];k++){
        i=ch[i][s[k]-'a'];
        for(int j = i;j&&~cnt[j];j=nex[j])ans+=cnt[j],cnt[j]=-1;
    }
    return ans;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++)cin>>pat,build_Trie();
    build_AC();
    cin>>s;
    cout<<query();
    return 0;
}