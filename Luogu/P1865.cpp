#include<iostream>
using namespace std;
int f[1000001],n,m,l,r;
bool vis[1000001];
int main(){
    scanf("%d%d",&m,&n);
    f[1]=0,vis[1]=true;
    for(int i=2;i<=n;i++){
        if(vis[i]==false){
            f[i]=f[i-1]+1;
            for(int j=i+i;j<=n;j=j+i) vis[j]=true;
        }
        else f[i]=f[i-1];
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l,&r);
        if(l<1 || r>n) printf("Crossing the line\n");
        else {
            int y=f[r]-f[l-1];
            printf("%d\n",y);
        }
    }
    return 0;
}
