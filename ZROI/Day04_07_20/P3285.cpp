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
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,idx,root,last=0;
map<int,int>M;
struct node{
    int lc;
    int rc;
    int size;
    int key;
    int l_lim;
    int r_lim;
    int fa;
}tr[1000005];
void pushup(int pos){
    tr[tr[pos].lc].fa=tr[tr[pos].rc].fa=pos;
    tr[pos].size=tr[tr[pos].lc].size+tr[tr[pos].rc].size+tr[pos].r_lim-tr[pos].l_lim+1;
}
int newnode(int l_lim,int r_lim){
    tr[++idx].size=r_lim-l_lim+1;
    tr[idx].key=rand();
    tr[idx].l_lim=l_lim;
    tr[idx].r_lim=r_lim;
    M[l_lim]=idx;
    return idx;
}
void split(int pos,int val,int &l_t,int &r_t){
    if(!pos)return l_t=r_t=0,void();
    if(tr[tr[pos].lc].size<val){
        split(tr[pos].rc,val-tr[tr[pos].lc].size-(tr[pos].r_lim-tr[pos].l_lim+1),tr[pos].rc,r_t);
        l_t=pos;
        tr[tr[pos].rc].fa=pos;
    }else{
        split(tr[pos].lc,val,l_t,tr[pos].lc);
        r_t=pos;
        tr[tr[pos].lc].fa=pos;
    }
    pushup(pos);
}
/* void split(int pos,int val,int &l_t,int &r_t){
    if(!pos)return l_t=r_t=0,void();
    if(tr[tr[pos].lc].size>=val){
        split(tr[pos].lc,val,l_t,r_t);
        tr[pos].lc=r_t;
        r_t=tr[r_t].fa=pos;
    }else{
        split(tr[pos].rc,val-tr[tr[pos].lc].size-(tr[pos].r_lim-tr[pos].l_lim+1),l_t,r_t);
        tr[pos].rc=l_t;
        l_t=tr[l_t].fa=pos;
    }
    pushup(pos);
} */
int merge(int l_t,int r_t){
    if(!l_t||!r_t)return l_t+r_t;
    if(tr[l_t].key<tr[r_t].key){
        tr[l_t].rc=merge(tr[l_t].rc,r_t);
        pushup(l_t);return l_t;
    }else{
        tr[r_t].lc=merge(l_t,tr[r_t].lc);
        pushup(r_t);return r_t;
    }
}
void insert(int val, int l_lim, int r_lim){
    int now = newnode(l_lim, r_lim),l_t,r_t;
    split(root,val-1,l_t,r_t);
    root = merge(merge(l_t,now),r_t);
}
void del(int l_Lim,int r_lim){
    int l_t,m_t,r_t;
    split(root,r_lim,l_t,r_t);
    split(l_t,l_Lim-1,l_t,m_t);
    root = merge(l_t,r_t);
}
int kth(int pos, int val){
    if(tr[tr[pos].lc].size>=val) return kth(tr[pos].lc,val);
    val-=tr[tr[pos].lc].size;
    if(val<=tr[pos].r_lim-tr[pos].l_lim+1)return tr[pos].l_lim+val-1;
    return kth(tr[pos].rc,val-(tr[pos].r_lim-tr[pos].l_lim+1));
}
int get_rank(int pos){
    int ans=tr[pos].size-tr[tr[pos].rc].size;
    while(pos!=root){
        if(tr[tr[pos].fa].rc==pos)ans+=tr[tr[pos].fa].size-tr[pos].size;
        pos=tr[pos].fa;
    }
    //printf("getrank: %d return %d\n",pos,ans);
    return ans;
}
int main(){
    n=read(),m=read();
    M[1]=1;
    insert(1,1,n);
    for(int i = 1,opt,x,y;i<=m;i++){
        opt=read();
        if(opt==1){
            x=read()-last,y=read()-last;
            int l=(--M.lower_bound(x+1))->first;
            int pos = M[l];
            int r=tr[pos].r_lim;
            last = get_rank(pos)+x-r;
            cout<<last<<endl;
            del(last-(x-l),last-(x-r));
            if(x>l)insert(last-x+l,l,x-1);
            insert(last,y,y);
            if(r>x)insert(last+1,x+1,r);
        }
        else if (opt==2){
            x=read()-last;
            int l=(--M.lower_bound(x+1))->first;
            int pos = M[l];
            int r=tr[pos].r_lim;
            last = get_rank(pos)+x-r;
            cout<<last<<endl;
            del(last-(x-l),last-(x-r));
            if(x>l)insert(last-(x-l),l,x-1);
            if(r>x)insert(last,x+1,r);
            insert(1,x,x);

        }else if (opt==3){
            x=read()-last;
            int l=(--M.lower_bound(x+1))->first;
            int pos = M[l];
            int r=tr[pos].r_lim;
            last = get_rank(pos)+x-r;
            cout<<last<<endl;
            del(last-(x-l),last-(x-r));
            if(x>l)insert(last-(x-l),l,x-1);
            if(r>x)insert(last,x+1,r);
            insert(n,x,x);
        }else{
            x=read()-last;
            last=kth(root,x);
            cout<<last<<endl;
        }
    }
    return 0;
}
