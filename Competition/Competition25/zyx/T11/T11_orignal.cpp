#include<iostream>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int x;
    int y;
    bool operator < (const node &w)const{return w.y>y;}
};
int x,y;
priority_queue<node>Q,q;
int main(){
    int n=read();
    for(int i = 1;i<=n;i++){
        x=read(),y=read();
        Q.push((node){x,y});
    }
    long long ans=0;
    while(Q.size()){
        ans++;
        node now=Q.top();
        Q.pop();
        int S=Q.size();
        for(int i = 1;i<=S;i++){
            node no=Q.top();Q.pop();
            if(abs(no.x-now.x)<=now.y-no.y) continue;
            q.push(no);
        }
        swap(Q,q);
    }
    cout<<ans;
}