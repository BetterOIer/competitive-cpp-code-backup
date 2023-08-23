#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector<int>ro[200005];
map<string,int>reff;
int ru[400005];
int cnt=0;
int n;
bool Topo(){
    queue<int> Q;
    int sum=0;
    for(int i=1;i<=cnt;i++)if(ru[i]==0)Q.push(i);
    while(!Q.empty())
    {
        int u=Q.front(); Q.pop();
        sum++;
        for(int to:ro[u])
        {
            if(--ru[to]==0) Q.push(to);
        }
    }
    return sum==cnt;
}
int main(){
    n=read();
    string s1,s2;
    for(int i = 1;i<=n;i++){
        cin>>s1>>s2;
        if(!reff[s1])reff[s1]=++cnt;
        if(!reff[s2])reff[s2]=++cnt;
        ro[reff[s1]].push_back(reff[s2]);
        ru[reff[s2]]++;
    }
    if(Topo()) cout<<"Yes";
    else cout<<"No";
}