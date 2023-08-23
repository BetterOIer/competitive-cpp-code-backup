#include<iostream>
using namespace std;
struct node{
    int F,M,R;
    int fa=0;
}tree[123];
int jl[50],k=0;
int findroot(int now=0){
    if(now==0){
        int i;
        bool flag=false;
        for(i = 65;i<=122;i++){
            if(tree[i].fa!=0){
                flag=true;
                break;
            }
        }
        if(flag)return findroot(i);
        else return -1;
    }else{
        if(tree[now].fa!=0){
            now=tree[now].fa;
            return findroot(now);
        }else{
            return now;
        }
    }
}
void zyx(int root){
    cout<<(char)root;
    if(tree[root].F!=0) zyx(tree[root].F);
    if(tree[root].M!=0) zyx(tree[root].M);
    if(tree[root].R!=0) zyx(tree[root].R);
}
void yqx(int root){
    if(tree[root].R!=0) yqx(tree[root].R);
    if(tree[root].F!=0) yqx(tree[root].F);
    cout<<(char)root;
    if(tree[root].M!=0) yqx(tree[root].M); 
}
void zzx(int root){
    if(tree[root].M!=0) zzx(tree[root].M); 
    cout<<(char)root;
    if(tree[root].R!=0) zzx(tree[root].R);
    if(tree[root].F!=0) zzx(tree[root].F);
}
int main(){
    int n;
    cin>>n;
    char a,b,c,d;
    while(cin>>a>>b>>c>>d){
        jl[++k]=a;
        if(b!='*'){
            tree[a].F=b;
            tree[b].fa=a;
        }
        if(c!='*'){
            tree[a].M=c;
            tree[c].fa=a;
        }
        if(d!='*'){
            tree[a].R=d;
            tree[d].fa=a;
        }
    }
    int po=findroot();
    if(po==-1){
        cout<<(char)jl[k]<<endl<<(char)jl[k]<<endl<<(char)jl[k]<<endl;
        return 0;
    }
    zyx(po);
    cout<<endl;
    zzx(po);
    cout<<endl;
    yqx(po);
}