#include<iostream>
using namespace std;
int fa[50000];
int find(int x){
    if(x==fa[x])return x;
    return find(fa[x]);
}
void join(int c1,int c2){
    int f1=find(c1),f2=find(c2);
    if(f1!=f2) fa[f1]=f2;
}
int main(){
    int n,m,p,x,y;
    cin>>n>>m>>p;
    for(int i = 1;i<=n;i++) fa[i]=i;
    for(int i = 0;i<=m-1;i++){
        cin>>x>>y;
        join(x,y);
    }
    for(int i = 1;i<=p;i++){
        cin>>x>>y;
        if(find(x)==find(y))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}