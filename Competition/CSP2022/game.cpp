#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
    char c=getchar();int x=0,f=1;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int A[100005],B[100005];
int n,m,q;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i = 1;i<=n;i++)A[i]=read();
    for(int i = 1;i<=m;i++)B[i]=read();
    for(int i = 1;i<=q;i++){
        int l1=read(),r1=read(),l2=read(),r2=read();
        if(l1==r1||l2==r2){
            if(l1==r1){
                if(A[l1]>0){
                    int minn=1000000000;
                    for(int i = l2;i<=r2;i++){
                        minn=min(minn,B[i]);
                    }
                    cout<<1LL*A[l1]*minn<<endl;
                }else if(A[l1]==0)cout<<0<<endl;
                else if(A[l1]<0){
                    int maxn=-1000000000;
                    for(int i = l2;i<=r2;i++){
                        maxn=max(maxn,B[i]);
                    }
                    cout<<1LL*A[l1]*maxn<<endl;
                }
            }else{
                if(B[l2]>0){
                    int maxn=-1000000000;
                    for(int i = l1;i<=r1;i++){
                        maxn=max(maxn,A[i]);
                    }
                    cout<<1LL*B[l2]*maxn<<endl;
                }else if(B[l2]==0)cout<<0<<endl;
                else if(B[l2]<0){
                    int minn=1000000000;
                    for(int i = l1;i<=r1;i++){
                        minn=min(minn,A[i]);
                    }
                    cout<<1LL*B[l2]*minn<<endl;
                }
            }
        }
        else{
        	int maxa=-1000000000,minb=1000000000;
        	for(int i = l1;i<=r1;i++){
        		maxa=max(maxa,A[i]);
			}for(int i = l2;i<=r2;i++){
        		minb=min(minb,B[i]);
			}
			cout<<1LL*maxa*minb<<endl;
		}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}