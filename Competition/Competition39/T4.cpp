#include<iostream>
using namespace std;
const long long maxans=1073741824;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int l;
    int r;
    long long valm=1;
    long long vall=1;
    long long valr=1;
    long long malm=1;
    long long mall=1;
    long long malr=1;
    long long VAL=1;
    bool TooLarge=false;
}tree[206];
void pushup(int pos){
    tree[pos].l=tree[pos<<1].l;
    tree[pos].r=tree[pos<<1|1].r;
    if(tree[pos<<1].TooLarge||tree[pos<<1|1].TooLarge){
        tree[pos].TooLarge=true;
    }else{
        tree[pos].VAL=tree[pos<<1].VAL*tree[pos<<1|1].VAL;
        tree[pos].vall=max(tree[pos<<1].vall,max(tree[pos<<1].VAL*tree[pos<<1|1].vall,tree[pos<<1].VAL*tree[pos<<1|1].mall));
        tree[pos].valr=max(tree[pos<<1|1].valr,max(tree[pos<<1|1].VAL*tree[pos<<1].valr,tree[pos<<1|1].VAL*tree[pos<<1].mall));
        tree[pos].valm=max(tree[pos<<1].valm,max(tree[pos<<1|1].valm,max(tree[pos<<1].valr*tree[pos<<1|1].vall,max(tree[pos<<1].malr*tree[pos<<1|1].vall,max(tree[pos<<1].valr*tree[pos<<1|1].mall,tree[pos<<1].malr*tree[pos<<1|1].mall)))));
        tree[pos].mall=min(tree[pos<<1].mall,min(tree[pos<<1].VAL*tree[pos<<1|1].mall,tree[pos<<1].VAL*tree[pos<<1|1].vall));
        tree[pos].malr=min(tree[pos<<1|1].malr,min(tree[pos<<1|1].VAL*tree[pos<<1].valr,tree[pos<<1|1].VAL*tree[pos<<1].malr));
        tree[pos].malm=min(tree[pos<<1].malm,min(tree[pos<<1|1].malm,min(tree[pos<<1].valr*tree[pos<<1|1].vall,min(tree[pos<<1].valr*tree[pos<<1|1].mall,min(tree[pos<<1].malr*tree[pos<<1|1].vall,tree[pos<<1].malr*tree[pos<<1|1].mall)))));
        if(tree[pos].valm>maxans){
            tree[pos].TooLarge=true;
        }
    }
}
void build(int pos,int l,int r){
    if(l==r){
        tree[pos].VAL=read();
        tree[pos].valm=tree[pos].vall=tree[pos].valr=tree[pos].malm=tree[pos].mall=tree[pos].malr=tree[pos].VAL;
        tree[pos].l=tree[pos].r=l;
        return;
    }
    int mid=(l+r)>>1;
    build(pos<<1,l,mid);
    build(pos<<1|1,mid+1,r);
    pushup(pos);
}
void update(int pos,int po,int data){
    int l=tree[pos].l,r=tree[pos].r;
    if(l==r){
        tree[pos].VAL=data;
        tree[pos].valm=tree[pos].vall=tree[pos].valr=tree[pos].malm=tree[pos].mall=tree[pos].malr=tree[pos].VAL;
        return;
    }
    int mid=(l+r)>>1;
    if(mid<po)update(pos<<1|1,po,data);
    else update(pos<<1,po,data);
    pushup(pos);
}
node query(int pos,int x,int y){
    int l=tree[pos].l,r=tree[pos].r;
    if(x<=l&&r<=y)return tree[pos];
    int mid=(l+r)>>1;
    node ans,Lans,Rans;
    if(mid<y) Lans=query(pos<<1|1,x,y);
    else if(mid>=x) Rans=query(pos<<1,x,y);
    if(Lans.TooLarge||Rans.TooLarge){
        ans.TooLarge=true;
    }else{
        ans.VAL=Lans.VAL*Rans.VAL;
        ans.vall=max(Lans.vall,max(Lans.VAL*Rans.vall,Lans.VAL*Rans.mall));
        ans.valr=max(Rans.valr,max(Rans.VAL*Lans.valr,Rans.VAL*Lans.mall));
        ans.valm=max(Lans.valm,max(Rans.valm,max(Lans.valr*Rans.vall,max(Lans.malr*Rans.vall,max(Lans.valr*Rans.mall,Lans.malr*Rans.mall)))));
        ans.mall=min(Lans.mall,min(Lans.VAL*Rans.mall,Lans.VAL*Rans.vall));
        ans.malr=min(Rans.malr,min(Rans.VAL*Lans.valr,Rans.VAL*Lans.malr));
        ans.malm=min(Lans.malm,min(Rans.malm,min(Lans.valr*Rans.vall,min(Lans.valr*Rans.mall,min(Lans.malr*Rans.vall,Lans.malr*Rans.mall)))));
        if(ans.valm>maxans){
            ans.TooLarge=true;
        }
    }
    return ans;
}
int main(){
    int n=read(),q=read();
    build(1,1,n);
    for(int i = 1,opt,x,y;i<=q;i++){
        opt=read(),x=read(),y=read();
        if(opt==1) update(1,x,y);
        else{
            node ans=query(1,x,y);
            if(ans.TooLarge) cout<<"Too large\n";
            else cout<<ans.valm<<"\n";
        }
    }
    return 0;
}