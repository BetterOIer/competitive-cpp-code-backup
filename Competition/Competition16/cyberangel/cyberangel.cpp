#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct node{
    int x;
    int y;
    int ans;
    int id;
}q[8003];
int p=1,a[8003],dp[8003];
bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmp1(node a,node b){
    return a.id<b.id;
}
int main(){
    freopen("cyberangel.in","r",stdin);
    freopen("cyberangel.out","w",stdout);
    int n=read(),Q=read();
    for(int i = 1;i<=n;i++){
        dp[i]=a[i]=read();
    }
    for(int i = 1;i<=Q;i++){
        q[i].x=read();
        q[i].y=read();
        q[i].id=i;
    }
    sort(q+1,q+n+1,cmp);
    for(int i = 1;i<=200005;i++){
        for(int j = 2;j<=n;j++){
            dp[j]=dp[j]^dp[j-1];
        }
        while(q[p].x==i){
            for(int j = 1;j<=n&&q[p].x==i;j++){
                if(q[p].y==j){
                    q[p].ans=dp[j];
                    p++;
                }
            }
        }
    }
    sort(q+1,q+n+1,cmp1);
    for(int i = 1;i<=n;i++){
        write(q[i].ans);
        puts("");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}