#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,a[25],count=0;
void solve(int whi){
    int ANS=0x3f3f3f3f;
    for(int i = 1;i<=n;i++){
        int p1=i-1,p2=i+1,ans=0;
        if(a[i]==whi)continue;
        for(int j = 1;j<=n;j++){
            if(a[j]==1-whi){
                int minx=min(abs(j-p1),abs(j+n-p1));
                int miny=min(abs(j-p2),abs(j+n-p2));
                if(miny>minx){
                    p1--;
                    ans+=minx;
                }else{
                    p2++;
                    ans+=miny;
                }
            }
        }
        if(ans<ANS)ANS=ans;
    }
    cout<<ANS;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        if(a[i]==1){
            ++count;
        }
    }
    if(count<2){
        cout<<0;
        return 0;
    }
    if(count<n-count) solve(0);
    else solve(1);
}