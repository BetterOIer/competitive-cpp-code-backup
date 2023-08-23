#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node1{
    vector <int> son;
    int bigson;
    int bsn=-1;
    int fa;
    int idx;
    int size;
}ro[100000];
struct node2{
    int l;
    int r;
    int mid;
    int val;
    int lazy;
}tree[1000000];
int cnt=0,rev[100000];
//Tree chain segmentation
void dfs_1(int now,int fa){
    ro[now].size=1;
    ro[now].fa=fa;
    for(auto i:ro[now].son){
        if(i==fa)continue;
        dfs_1(i,now);
        ro[now].size+=ro[i].size;
        if(ro[now].bsn<ro[i].size){
            ro[now].bsn=ro[i].size;
            ro[now].bigson=i;
        }
    }
}
void dfs_2(int now,int fa){
    ro[now].idx=++cnt;
    rev[cnt]=now;
    if(ro[now].son.size()==0) return ;
    dfs_2(ro[now].bigson,fa);
    for(auto i:ro[now].son){
        if(i==ro[now].fa||i==ro[now].bigson)continue;
        dfs_2(i,i);
    }
}
//Segment Tree
void pushup(int pos){
    tree[pos].val=tree[pos<<1].val+tree[pos<<1|1].val;
}
void pushdown(int pos){
    if(tree[pos].lazy){
        tree[pos<<1].val=tree[pos<<1].r-tree[pos<<1].l+1-tree[pos<<1].val;
        tree[pos<<1|1].val=tree[pos<<1|1].r-tree[pos<<1|1].l+1-tree[pos<<1|1].val;
        tree[pos<<1].lazy^=1;
        tree[pos<<1|1].lazy^=1;
    }
    tree[pos].lazy=0;
}
void build(int pos,int l,int r){
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].mid=(l+r)>>1;
    tree[pos].val=0;
    if(l==r) return;
    build(pos<<1,l,tree[pos].mid);
    build(pos<<1|1,tree[pos].mid+1,r);
    pushup(pos);
}
void update(int pos,int x,int y){
    int l=tree[pos].l,r=tree[pos].r,mid=tree[pos].mid;
    if(x<=l&&r<=y){
        tree[pos].val=(r-l+1)-tree[pos].val;
        tree[pos].lazy^=1;
        return;
    }
    pushdown(pos);
    if(mid<y) update(pos<<1|1,x,y);
    if(mid>=x) update(pos<<1,x,y);
    pushup(pos);
}
int query(int pos,int x,int y){
    int l=tree[pos].l,r=tree[pos].r,mid=tree[pos].mid;
    int ans=0;
    if(x<=l&&r<=y){
        return tree[pos].val;
    }
    pushdown(pos);
    if(mid<y) ans+=query(pos<<1|1,x,y);
    if(mid>=x) ans+=query(pos<<1,x,y);
    return ans;
}
//main
int main(){
    freopen("T269623.in","r",stdin);
    freopen("T269623.ans1","w",stdout);
    int n=read(),m,u,v,who;
    char c;
    for(int i = 1;i<=n-1;i++){
        u=read(),v=read();
        ro[u].son.push_back(v);
        ro[v].son.push_back(u);
    }
    dfs_1(1,0);
    dfs_2(1,1);
    build(1,1,cnt);
    m=read();
    while(m--){
        c=getchar();
        who=read();
        if(c=='Q'){
            cout<<query(1,ro[who].idx,ro[who].idx+ro[who].size-1)<<endl;
        }else{
            update(1,ro[who].idx,ro[who].idx+ro[who].size-1);
        }
    }
}