/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int maxn=50005;
int ch[maxn][26],ne[maxn],idx=0;
struct ANS{
    int num=0;
    int pos=0;
    bool have=false;
    string str;
}num[maxn];
string master_s,pattern_s;
bool cmp(ANS a, ANS b){
    if(a.num*a.have==b.num*b.have){
        return a.pos<b.pos;
    }
    return a.num*a.have>b.num*b.have;
}
void build_ac(){
     queue<int>q;
     for(int i = 0;i<26;i++){
        if(ch[0][i])q.push(ch[0][i]);
     }
     while(q.size()){
        int u=q.front();q.pop();
        for(int i =0;i<26;i++){
            int v=ch[u][i];
            if(v)ne[v]=ch[ne[u]][i],q.push(v);
            else ch[u][i]=ch[ne[u]][i];
        }
     }
}
void query(){
    for(int k=0,i=0;master_s[k];k++){
        i=ch[i][master_s[k]-'a'];
        for(int j = i;j;j=ne[j]){
            num[j].num++;
        }
    }
}
void build_trie(){
    int p=0;
    for(int i = 0;pattern_s[i];i++){
        int j=pattern_s[i]-'a';
        if(!ch[p][j])ch[p][j]=++idx;
        p=ch[p][j];
    }
    num[p].pos=p;
    num[p].str=pattern_s;
    num[p].have=true;
}
int main(){
    int n=read();
    while(n){
        for(int i = 1;i<=n;i++){
            cin>>pattern_s;
            build_trie();
        }
        build_ac();
        cin>>master_s;
        query();
        sort(num+1,num+idx+1,cmp);
        cout<<num[1].num<<endl;
        for(int i = 1;i<=idx;i++){
            if(num[i].num==num[1].num&&num[i].have){
                cout<<num[i].str<<endl;
            }
        }
        memset(ch,0,sizeof ch);
        memset(num,0,sizeof num);
        memset(ne,0,sizeof ne);
        idx=0;
        n=read();
    }
    return 0;
}