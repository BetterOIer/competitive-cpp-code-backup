#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int tot=-1,all=0;
struct node{
    int val;
    int time;
};
vector<node>V;
map<int ,int> M;
map<int,node> t;
void inset(int num,int tim){
    if(M.find(num)==M.end()){
        M[num]=++tot;
        V.push_back((node){num,tim});
    }else V[M[num]].time+=tim;
}
void Temp(int num,int tim){
    if(t.find(num)==t.end()){
        t[++all]=(node){num,tim};
    }else t[num].time+=tim;
}
bool cmp(node a,node b){
    return a.val>b.val;
}
int main(){
    freopen("kth.in","r",stdin);
    freopen("kth.out","w",stdout);
    int n=read(),k=read();
    for(int i = 1;i<=n;i++){
        int num=read();
        int len=V.size();
        Temp(num,1);
        for(int j = 0;j<len;j++)Temp(V[j].val+num,V[j].time);
        for(int j = 1;j<=all;j++)inset(t[j].val,t[j].time);
        t.clear();all=0;
    }
    sort(V.begin(),V.end(),cmp);
    int cnt=0,i;
    for(i = 0;i<=tot&&cnt<k;i++)cnt+=V[i].time;
    cout<<V[i-1].val<<endl;
    return 0;
}