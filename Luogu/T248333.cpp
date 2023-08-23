#include<iostream>
using namespace std;
struct node{
    int D,R,L;
}tree[2097152];
int n;
void deal(int po){
    if(po*2<=n) {tree[po*2].D=1;deal(po*2);}
    if(po*2+1<=n) {tree[po*2+1].D=0;deal(po*2+1);}
}
void dfs(int now){
    if(now*2<=n) dfs(now*2);
    if(tree[now].D) cout<<"down ";
    else cout<<"up ";
    if(now*2+1<=n) dfs(now*2+1);
}
int main(){
    cin>>n;
    n=(1<<n)-1;
    tree[1].D=1;
    deal(1);
    dfs(1);
}