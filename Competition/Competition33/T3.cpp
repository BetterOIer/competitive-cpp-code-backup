#include<iostream>
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
bool Matrix[30][30];
bool check(int sty,int stx,int eny,int enx){
    int i;
    for(i = sty;i<=((sty+eny-1)>>1);i++){
        for(int j = stx;j<=enx;j++){
            if(Matrix[i][j]!=Matrix[eny-i+sty][enx-j+stx]){
                return false;
            }
        }
    }
    i--;
    if(i==((sty+eny)>>1))return true;
    else i=(sty+eny)>>1;
    for(int j = stx;j<=((enx+stx-1)>>1);j++){
        if(Matrix[i][j]!=Matrix[i][enx-j+stx]){
            return false;
        }
    }
    return true;
}
int maxn=0;
int main(){
    int n=read(),m=read();
    string s;
    for(int i =1;i<=n;i++){
        cin>>s;
        for(int j= 0;j<m;j++){
            Matrix[i][j+1]=s[j]-'0';
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int minn=min(n-i,m-j);
            for(int w = minn;w>=max(maxn,1);w--){
                if(check(i,j,i+w,j+w)){
                    maxn=max(maxn,w+1);
                }
            }
        }
    }
    if(maxn)cout<<maxn;
    else cout<<-1;
}