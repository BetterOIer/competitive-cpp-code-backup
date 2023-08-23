#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,d,all;
int a[1000006][5];
int ans[200],ANS;
int main(){
    n=read(),d=read();all=1<<d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            a[i][j]=read();
        }
    }
    for(int now=0;now<all;now++){
        ans[now]=-2147483647;
        for(int i=1;i<=n;i++){
            int w=0;
            for(int j=0;j<d;j++){
                if((now>>j)&1)w-=a[i][j+1];
                else w+=a[i][j+1];
            }
            ans[now]=max(w,ans[now]);
        }
    }
    for(int i=0;i<all;i++){
        ANS=max(ANS,ans[i]+ans[all-1-i]);
    }
    cout<<ANS<<endl;
    return 0;
}