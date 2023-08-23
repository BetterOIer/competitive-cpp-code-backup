#include<iostream>
using namespace std;
const int MAXN = 2e5+5;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[MAXN],ans[MAXN];
int main(){
    freopen("T265200.in","r",stdin);
    freopen("T265200.out","w",stdout);
    int n=read(),L=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    int nowbag=1,nowwei=0;
    for(int i = n;i>=1;i--){
        if(nowwei+a[i]<=L){
            nowwei+=a[i];
        }else{
            nowwei=a[i];
            nowbag++;
        }
        ans[i]=nowbag;
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
