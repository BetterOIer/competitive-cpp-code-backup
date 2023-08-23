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
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int ch[1000005][26],idx,n,bs[1000005];
int nex[1000005],cnt[1000005],tim[1000005],fa[1000005];
string s,pat;
struct node{
    int tim;
    int num;
};
vector<node>v;
bool operator < (node a,node b){
    return a.tim<b.tim;
}
void insert(int ti){
    int pos=0;
    for(int i = 0;pat[i];i++){
        int j = pat[i]-'a';
        if(!ch[pos][j]){
            ch[pos][j]=++idx;
            fa[ch[pos][j]]=pos;
            bs[pos]=j;
        }
        pos=ch[pos][j];
    }
    ++cnt[pos];tim[pos]=ti;
}
void build(){
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
        for(int j = i;j&&~cnt[j];j=nex[j]){
            if(ans<cnt[j]){
                ans=cnt[j];
                v.clear();
                v.push_back((node){tim[j],j});
            }else if(ans==cnt[j]){
                v.push_back((node){tim[j],j});
            }
            cnt[j]=-1;
        }
    }
    return ans;
}
void dfs(int pos){
    if(fa[pos]==0){
        cout<<(char)(bs[pos]+'a');
        return ;
    }dfs(fa[pos]);
    cout<<(char)(bs[pos]+'a');
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++)cin>>pat,insert(i);
    build();
    cin>>s;
    cout<<query()<<endl;
    sort(v.begin(),v.end());
    for(node i:v){
        dfs(i.tim);
        cout<<endl;
    }
    return 0;
}