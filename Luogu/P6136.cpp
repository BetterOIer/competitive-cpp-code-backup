#include<iostream>
using namespace std;
const long long N = 4000005;  
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    long long s[2];
    long long fa;
    long long val;
    long long cnt;
    long long size;
    void init(long long fanew,long long valnew){
        fa=fanew,val=valnew;
        cnt=size=1;
    }
}tree[N];
long long root,n,idx,m;
void pushup(long long pos){
    tree[pos].size=tree[tree[pos].s[0]].size+tree[tree[pos].s[1]].size+tree[pos].cnt;
}
void rotate(long long pos){
    long long fa=tree[pos].fa,grandfa=tree[fa].fa;
    long long fich = tree[fa].s[1]==pos;
    tree[fa].s[fich]=tree[pos].s[fich^1];
    tree[tree[pos].s[fich^1]].fa=fa;
    tree[pos].s[fich^1]=fa;
    tree[fa].fa=pos;
    tree[grandfa].s[tree[grandfa].s[1]==fa]=pos;
    tree[pos].fa=grandfa;
    pushup(fa),pushup(pos);
}
void splay(long long pos,long long goal){
    while(tree[pos].fa!=goal){
        long long fa=tree[pos].fa,grandfa=tree[fa].fa;
        if(grandfa!=goal) ((tree[fa].s[0]==pos)^(tree[grandfa].s[0]==fa))? rotate(pos):rotate(fa);
        rotate(pos);
    }
    if(goal==0) root=pos;
}
void find(long long val){
    long long pos=root;
    while(tree[pos].s[val>tree[pos].val]&&val!=tree[pos].val)pos=tree[pos].s[val>tree[pos].val];
    splay(pos,0);
}
long long get_pre(long long val){
    find(val);
    long long pos=root;
    if(tree[pos].val<val)return pos;
    pos=tree[pos].s[0];
    while(tree[pos].s[1])pos=tree[pos].s[1];
    return pos;
}
long long get_aft(long long val){
    find(val);
    long long pos=root;
    if(tree[pos].val>val)return pos;
    pos=tree[pos].s[1];
    while(tree[pos].s[0])pos=tree[pos].s[0];
    return pos;
}
void del(long long val){
    long long pre=get_pre(val);
    long long aft=get_aft(val);
    splay(pre,0);splay(aft,pre);
    long long del=tree[aft].s[0];
    if(tree[del].cnt>1)tree[del].cnt--,splay(del,0);
    else tree[aft].s[0]=0; 
}
long long get_rank(long long val){
    find(val);
    if(val!=tree[root].val)return tree[tree[root].s[0]].size+1;
    return tree[tree[root].s[0]].size;
}
long long get_kth(long long k){
    long long pos=root;
    while(true){
        long long fich=tree[pos].s[0];
        if(tree[fich].size+tree[pos].cnt<k){
            k-=(tree[fich].size+tree[pos].cnt);
            pos=tree[pos].s[1];
        }else{
            if(tree[fich].size>=k)pos=tree[pos].s[0];
            else break;
        }
    }
    splay(pos,0);
    return tree[pos].val;
}
void insert(long long val){
    long long pos=root,fa=0;
    while(pos&&tree[pos].val!=val) fa=pos,pos=tree[pos].s[val>tree[pos].val];
    if(pos)tree[pos].cnt++;
    else{
        pos=++idx;
        tree[fa].s[val>tree[fa].val]=pos;
        tree[pos].init(fa,val);
    }
    splay(pos,0);
}
int main(){
    insert(-1e9);insert(1e9);
    m=read(),n=read();
    while(m--){
        long long x=read();
        insert(x);
    }
    long long ans=0;
    long long x=0;
    while(n--){
        long long opt=read(),num=read();
        num^=x;
        if(opt==1)insert(num);
        if(opt==2)del(num);
        if(opt==3){x=get_rank(num);ans^=x;}
        if(opt==4){x=get_kth(num+1);ans^=x;}
        if(opt==5){x=tree[get_pre(num)].val;ans^=x;}
        if(opt==6){x=tree[get_aft(num)].val;ans^=x;}
    }
    cout<<ans;
    return 0;
}