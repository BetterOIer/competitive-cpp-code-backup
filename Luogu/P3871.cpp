#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> g;
priority_queue<int, vector<int>, greater<int> > l;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void insert(int x) {
    if(!g.size() || x < g.top()) g.push(x);
    else l.push(x);
    if(g.size() > l.size() + 1) l.push(g.top()), g.pop();
    if(l.size() > g.size() + 1) g.push(l.top()), l.pop();
}
int main(){
    int n,p;
    string s;
    cin>>n;
    for(int i = 1;i<=n;i++){
        p=read();
        insert(p);
    }
    cin>>p;
    for(int i = 1;i<=p;i++){
        cin>>s;
        if(s=="add"){
            n=read();
            insert(n);
        }else{
            if(g.size()>=l.size())cout<<g.top()<<endl;
            else cout<<l.top()<<endl;
        }
    }
}