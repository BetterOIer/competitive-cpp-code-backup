/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,ty,last,tim;//注意n,m, ty强制在线
int root[500005],add[500005];
pair<int, int> max(pair<int, int> A, pair<int, int> B){
    return A.first > B.first ? A : B;
}
namespace Seg{
    struct node{
        int val;
        int tag;
    }tr[500005<<2];
    void pushup(int pos){
        tr[pos].val=tr[pos<<1].val+tr[pos<<1|1].val;
    }
    void pushdown(int pos,int l,int r){
        if(!tr[pos].tag)return;
        int mid = (l+r)>>1;
        tr[pos<<1].val=(mid-l+1)*tr[pos].tag;
        tr[pos<<1|1].val=(r-mid)*tr[pos].tag;
        tr[pos<<1].tag=tr[pos].tag;
        tr[pos<<1|1].tag=tr[pos].tag;
        tr[pos].tag=0;
    }
    void update(int pos,int l,int r,int x, int y,int val){//修改直接是覆盖操作
        if(x<=l&&r<=y){
            tr[pos].val=val*(r-l+1);
            tr[pos].tag=val;
            return;
        }
        pushdown(pos,l,r);
        int mid = (l+r)>>1;
        if(mid>=x) update(pos<<1,l,mid,x,y,val);
        if(mid<y) update(pos<<1|1,mid+1,r,x,y,val);
        pushup(pos);
    }
    int query(int pos,int l, int r, int x,int y){
        if(x<=l&&r<=y){
            return tr[pos].val;
        }        
        pushdown(pos,l,r);
        int mid = (l+r)>>1,ans=0;
        if(mid>=x) ans+=query(pos<<1,l,mid,x,y);
        if(mid<y) ans+=query(pos<<1|1,mid+1,r,x,y);
        return ans;
    }
}
namespace Tim{
    int idx=0;
    
    struct node{
        int lc;
        int rc;
        int val;
        int tag[2];
    }tr[500005*625];
    void insert(int pre,int &pos,int l,int r,int x, int y,int val1,int val2){//修改直接是覆盖操作
        pos=++idx;tr[pos]=tr[pre];
        if(x<=l&&r<=y){
            tr[pos].tag[0]=val1;
            tr[pos].tag[1]=val2;
            return ;
        }
        int mid = (l+r)>>1;
        if(mid>=x) insert(tr[pre].lc,tr[pos].lc,l,mid,x,y,val1,val2);
        if(mid<y) insert(tr[pre].rc,tr[pos].rc,mid+1,r,x,y,val1,val2);
    }
    pair<int, int> query(int pos,int l, int r, int x){
        if(l==r){
            return make_pair(tr[pos].tag[0],tr[pos].tag[1]);
        }
        int mid = (l+r)>>1;
        if(mid>=x) return max(make_pair(tr[pos].tag[0],tr[pos].tag[1]),query(tr[pos].lc,l,mid,x));
        else return max(make_pair(tr[pos].tag[0],tr[pos].tag[1]), query(tr[pos].rc,mid+1,r,x));
    }
}
int main(){
    n=read(),m=read(),ty=read();
    for(int i = 1,opt,l,r,x;i<=m;i++){
        opt=read();
        if(opt==1){
            l=read(),r=read();
            l=(l+last*ty)%n+1,r=(r+last*ty)%n+1;
            if(l>r)swap(l,r);
            last = Seg::query(1,1,n,l,r);
            cout<<last<<endl;
        }else if(opt==2){
            l=read();
            l=(l+last*ty)%n+1;
            pair<int, int> now = Tim::query(root[tim],1,n,l);
            if(!now.second) continue;
            pair<int, int> tmp = Tim::query(root[now.second-1],1,n,l);
            Seg::update(1,1,n,l,l,add[tmp.second]);
            ++tim;
            Tim::insert(root[tim-1],root[tim],1,n,l,l,tim,tmp.second);
        }else{
            l=(read()+last*ty)%n+1,r=(read()+last*ty)%n+1,x=read();
            if(l>r)swap(l,r);
            add[++tim]=x;
            Seg::update(1,1,n,l,r,add[tim]);
            Tim::insert(root[tim-1],root[tim],1,n,l,r,tim,tim);
        }
    }
    return 0;
}