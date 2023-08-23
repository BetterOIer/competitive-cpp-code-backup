#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,M;
const int maxn=10;
int a[maxn][maxn];
int asked[maxn];
int main(){
    n=read();
    m=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    M=read();
    while(M--){
        for(int i = 1;i<=m;i++){
            cin>>asked[i];
        }
        int num=0;
        for(int i = 1;i<=n;i++){
            bool flag=true;
            for(int j = 1;j<=m;j++){
                if(asked[j]==-1)continue;
                if(asked[j]!=a[i][j]){
                    flag=false;
                    break;
                }
            }
            if(flag)num++;
        }
        cout<<num<<endl;
    }
}