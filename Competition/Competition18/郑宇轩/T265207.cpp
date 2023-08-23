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
const int mod = 1e9+7;
const int MAXN = 1e6+5;
const int INF = 2147483647;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int l;
    int r;
    int st;
    int ed;
    char c1,c2;
}tree[60];
string s;
int n;
bool combine(int pos1,int pos2){
    if(tree[pos1].ed+1==tree[pos2].st){
        if((tree[pos1].c1==tree[pos2].c1&&tree[pos1].c2==tree[pos2].c2&&s[tree[pos1].ed]!=s[tree[pos2].st])||(tree[pos1].c1==tree[pos2].c2&&tree[pos1].c2==tree[pos2].c1&&s[tree[pos1].ed]!=s[tree[pos2].st])||((tree[pos1].ed-tree[pos1].st+1)==1&&(tree[pos2].ed-tree[pos2].st+1)==1)||((tree[pos1].ed-tree[pos1].st+1)==1&&(tree[pos2].ed-tree[pos2].st+1)>1&&s[tree[pos2].st+1]==tree[pos1].c1)||((tree[pos1].ed-tree[pos1].st+1)>1&&(tree[pos2].ed-tree[pos2].st+1)==1&&s[tree[pos1].ed-1]==tree[pos2].c1)){
            return true;
        }
    }
    return false;
}
void pushup(int pos){
    if(combine(pos<<1,pos<<1|1)){
        tree[pos].st=tree[pos<<1].st;
        tree[pos].ed=tree[pos<<1|1].ed;
        tree[pos].c1=tree[pos<<1].c1;
        tree[pos].c2=tree[pos<<1].c2;
    }else{
        int len1=tree[pos<<1].ed-tree[pos<<1].st+1;
        int len2=tree[pos<<1|1].ed-tree[pos<<1|1].st+1;
        if(len1<len2) {
            tree[pos].st=tree[pos<<1|1].st;
            tree[pos].ed=tree[pos<<1|1].ed;
            tree[pos].c1=tree[pos<<1|1].c1;
            tree[pos].c2=tree[pos<<1|1].c2;
        }else if(len1>=len2){
            tree[pos].st=tree[pos<<1].st;
            tree[pos].ed=tree[pos<<1].ed;
            tree[pos].c1=tree[pos<<1].c1;
            tree[pos].c2=tree[pos<<1].c2;
        }
    }
}
void build(int l,int r,int pos){
    tree[pos].l=l,tree[pos].r=r;
    if(l==r){
        tree[pos].c1=s[l];
        tree[pos].c2=s[l];
        tree[pos].st=l;
        tree[pos].ed=l;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
    pushup(pos);
}
long long len=0;
int po;
char h1,h2;
void query(int x,int y,int pos){
    if(x<=tree[pos].l&&y>=tree[pos].r){
        len=tree[pos].ed-tree[pos].st+1;
        po=pos;
        return;
    }
    int mid=(tree[pos].l+tree[pos].r)>>1;
    long long ans=0;
    if(mid>=x){
        query(x,y,pos<<1);
        ans=max(ans,len);
    }
    if(mid<y){
        query(x,y,pos<<1|1);
        ans=max(ans,len);
    }
    len=ans;
}
int main(){
    freopen("T265207.in","r",stdin);
    freopen("T265207.out","w",stdout);
    cin>>s;
    n=s.length();
    build(0,n-1,1);
    int m=read(),l,r;
    for(;m--;){
        l=read(),r=read();
        len=0;
        query(l-1,r-1,1);
        cout<<len;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
