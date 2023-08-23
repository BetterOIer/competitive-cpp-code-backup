#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int l;
    int r;
    int val;
    int size;
    int dat;
}a[1000005];
int tot=0,root,x,y,z;
void update(int x){
    a[x].size=a[a[x].l].size+a[a[x].r].size+1;
}
void split(int now, int k,int &x,int &y){
    if(!now)x=y=0;
    else{
        if(a[now].val<=k){
            x=now, split(a[now].r,k,a[now].r,y);
        }else{
            y=now,split(a[now].l,k,x,a[now].l);
        }
        update(now);
    }
}
int New(int val){
    a[++tot].size=1;
    a[tot].dat=rand();
    a[tot].val=val;
    return tot;
}
int kth(int now,int k){
    while(true){
        if(k<=a[a[now].l].size) now=a[now].l;
        else{
            if(a[a[now].l].size+1==k){
                return now;
            }else{
                k-=a[a[now].l].size+1;
                now=a[now].r;
            }
        }
    }
}
int merge(int x,int y){
    if(!x||!y)return x+y;
    if(a[x].dat>a[y].dat){
        a[x].r=merge(a[x].r,y);
        update(x);
        return x;
    }else{
        a[y].l=merge(x,a[y].l);
        update(y);
        return y;
    }
}
int main(){
    int m,q,va,opt;
    cin>>m>>q;
    for(int i = 1;i<=m;i++){
        cin>>va;
        split(root,va,x,y);
        root = merge(merge(x,New(va)),y);
    }
    for(int i = 1;i<=q;i++){
        cin>>opt>>va;
        if(opt==1){
            printf("%d\n",a[kth(root,a[root].size-va+1)].val);
        }else if(opt==2){
            split(root,va,x,y);
            root = merge(merge(x,New(va)),y);
        }
    }
}