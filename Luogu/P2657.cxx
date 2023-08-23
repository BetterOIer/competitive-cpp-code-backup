#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a,b;
int num[11],f[11][11][2][2];
int dfs(int pos,int pre,int lim, int lead){
    if(pos==0) return 1;
    if(~f[pos][pre][lim][lead]) return f[pos][pre][lim][lead];
    int maxn=lim*num[pos]+(!lim)*9,res=0;
    for(int i = 0;i<=maxn;i++){
        if(abs(i-pre)<2&&(!lead))continue;
        res+=dfs(pos-1,i,lim&&(i==maxn),lead&&(i==0));
    } return f[pos][pre][lim][lead]=res;
}
int solve(int x){
    int len = 0;
    for(int i = 0;i<11;i++){
        num[i]=0;
    }
    for(int i = 0;i<11;i++){
        for(int j = 0;j<11;j++){
            f[i][j][0][0]=f[i][j][0][1]=f[i][j][1][0]=f[i][j][1][1]=-1;
        }
    }
    while(x){
        num[++len]=x%10;
        x/=10;
    }
    return dfs(len,0,1,1);
}
int main(){
    a=read(),b=read();
    cout<<solve(b)-solve(a-1);
}