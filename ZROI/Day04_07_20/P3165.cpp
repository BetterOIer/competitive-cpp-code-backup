/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,idx,root;
int ref[1000005];
struct node{
    int key;
    int val;
    int lc;
    int rc;
    int size;
    int minn;
    int tag;
}tr[1000005];
struct ORI{
    int num;
    int idx;
}a[1000005];
bool operator < (ORI a, ORI b){
    if (a.num != b.num) return a.num < b.num;
	return a.idx < b.idx;
}
bool operator > (ORI a, ORI b){
    if (a.num != b.num) return a.num > b.num;
	return a.idx > b.idx;
}
int newnode(int val){
    tr[++idx].key=rand();
    tr[idx].val=tr[idx].minn=val;
    tr[idx].size=1;
    return idx;
}
void pushup(int pos){
    tr[pos].size=tr[tr[pos].lc].size+tr[tr[pos].rc].size+1;
    tr[pos].minn=min(tr[pos].val,min((tr[pos].lc? tr[tr[pos].lc].minn:2147483647),(tr[pos].rc? tr[tr[pos].rc].minn:2147483647)));
}
void pushdown(int pos){
    if(!tr[pos].tag) return;
    swap(tr[pos].lc,tr[pos].rc);
    tr[tr[pos].lc].tag^=1;
    tr[tr[pos].rc].tag^=1;
    tr[pos].tag=0;
}
void split(int pos,int val,int &l_t,int &r_t){
    if(!pos)return l_t=r_t=0,void();
    pushdown(pos);
    if(tr[tr[pos].lc].size>=val){
        r_t=pos;
        split(tr[pos].lc,val,l_t,tr[pos].lc);
    }else{
        val-=tr[tr[pos ].lc].size+1;
        l_t=pos;
        split(tr[pos].rc,val,tr[pos].rc,r_t);
    }
    pushup(pos);
}
int merge(int l_t,int r_t){
    if(!l_t||!r_t)return l_t+r_t;
    if(tr[l_t].key<tr[r_t].key){
        pushdown(l_t);
        tr[l_t].rc = merge(tr[l_t].rc,r_t);
        pushup(l_t); return l_t;
    }else{
        pushdown(r_t);
        tr[r_t].lc=merge(l_t,tr[r_t].lc);
        pushup(r_t);return r_t;
    }
}
/* void insert(int val){
    int m_t=newnode(val);
    int l_t,r_t;
    split(root,val-1,l_t,r_t);
    root = merge(merge(l_t,m_t),r_t);
} */
int get_rank(int pos){
    int rank=1;
    while(true){
        pushdown(pos);
        if(tr[pos].lc&&tr[pos].minn==tr[tr[pos].lc].minn){
            pos=tr[pos].lc;
        }else if(tr[pos].rc&&tr[pos].minn==tr[tr[pos].rc].minn){
            rank+=tr[tr[pos].lc].size+1,pos=tr[pos].rc;
        }else {
            //printf("getrank: %d return %d\n",pos,rank + tr[tr[pos].lc].size);
            return rank + tr[tr[pos].lc].size;
        }
    }
}
void output(int pos){
    if(!pos)return;
    pushdown(pos);
    output(tr[pos].lc);
    cout<<tr[pos].val<<" ";
    output(tr[pos].rc);
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        a[i].num=read(),a[i].idx=i;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        ref[a[i].idx]=i;
    }
    for(int i = 1;i<=n;i++){
        root = merge(root,newnode(ref[i]));
    }
    //cout<<"origin: ";
    //output(root);
    //cout<<"\n";
    for(int i = 1;i<=n;i++){
        int rank = get_rank(root),l_t,m_t,r_t;
        cout<<rank+i-1<<" ";
        /* split(root,rank-1,l_t,r_t);
        split(r_t,rank,m_t,r_t); */
        split(root, rank, l_t, r_t);
		split(l_t, rank-1, l_t, m_t);
        tr[l_t].tag^=1;
        root = merge(l_t,r_t);
        //output(root);
        //cout<<"\n";
    }
    return 0;
}