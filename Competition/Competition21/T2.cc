#include<iostream>
using namespace std;
struct node{
    unsigned long long he;
    int gs;
}a[41];
bool hav[41];
int re[41],tot=0;
int squ[41][41];
unsigned long long ans;
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>u>>v;
        a[u].he+=v;
        a[u].gs++;
        hav[u]=true;
    }
    for(int i = 1;i<=40;i++){
        if(hav[i]){
            re[++tot]=i;
        }
    }
    for(int i = 1;i<=tot;i++){
        a[re[i]].he*=(1<<(a[re[i]].gs-1));
        ans+=a[re[i]].he;
    }
    for (int i=0;i<tot;i++){	
        for (int j=1;j<=i;j++){
            squ[i][j]=squ[i-1][j-1]+squ[i-1][j];
        }
        squ[i][0]=squ[i][i]=1;
	}
    long long mul=0;
    for(int i=m-1;i<=tot-1;i++){
        mul+=squ[tot-1][i];
    }
    cout<<mul*ans;
}