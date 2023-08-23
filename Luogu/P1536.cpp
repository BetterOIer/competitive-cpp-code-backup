#include<iostream>
#include<cstring>
using namespace std;
int vill[1001],m,n;
int find(int x){
    if(vill[x]==x)return x;
    return vill[x]=find(vill[x]);
}
void join(int a,int b){
    int f1=find(a),f2=find(b);
    if(f1!=f2) vill[f1]=f2;
}
int main(){
    while(true){
        cin>>n;
        if(n==0)break;
        cin>>m;
        for(int i = 1;i<=n;i++) vill[i]=i;
        for(int i = 1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            join(a,b);
        }
        int ans=-1;
        for(int i = 1;i<=n;i++){
            if(find(i)==i) ans++;
        }
        cout<<ans<<endl;
    }
}