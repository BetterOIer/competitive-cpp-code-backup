//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <thread>
#include <unordered_map>
#include <unordered_set>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int l;
    int r;
    int ans=0;
    int lazy=0;
}tree[2000000];
int tot=0;
string s;
void pushup(int pos){
    tree[pos].ans=tree[pos<<1].ans+tree[pos<<1|1].ans;
}
void pushdown(int pos){
    if(tree[pos].lazy){
        tree[pos<<1].ans=tree[pos].lazy%2==0? tree[pos<<1].ans:tree[pos<<1].r-tree[pos<<1].l+1-tree[pos<<1].ans;
        tree[pos<<1|1].ans=tree[pos].lazy%2==0? tree[pos<<1|1].ans:tree[pos<<1|1].r-tree[pos<<1|1].l+1-tree[pos<<1|1].ans;
        tree[pos<<1].lazy+=tree[pos].lazy;
        tree[pos<<1|1].lazy+=tree[pos].lazy;
        tree[pos].lazy=0;
    }
    return;
}
void build(int pos,int l,int r){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r){
        tree[pos].ans=s[tot++]-'0';
        return;
    }
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
    return;
}
void updata(int pos,int l,int r){
    if(tree[pos].l>=l&&tree[pos].r<=r){
        tree[pos].ans=tree[pos].r-tree[pos].l+1-tree[pos].ans;
        tree[pos].lazy++;
        return;
    }
    pushdown(pos);
    int mid=(tree[pos].l+tree[pos].r)>>1;
    if(mid>=l) updata(pos<<1,l,r);
    if(mid<r) updata(pos<<1|1,l,r);
    pushup(pos);
}
long long query(int x,int y,int pos){
    pushdown(pos);
    if(x<=tree[pos].l&&y>=tree[pos].r) return tree[pos].ans;
    int mid=(tree[pos].l+tree[pos].r)>>1;
    long long ans=0;
    if(mid>=x)ans+=query(x,y,pos<<1);
    if(mid<y)ans+=query(x,y,pos<<1|1);
    return ans;
}
int main(){
    int n=read(),m=read(),opt,n1,n2;
    cin>>s;
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        opt=read(),n1=read(),n2=read();
        if(!opt){
            updata(1,n1,n2);
        }else{
            cout<<query(n1,n2,1)<<endl;
        }
    }
    return 0;
}