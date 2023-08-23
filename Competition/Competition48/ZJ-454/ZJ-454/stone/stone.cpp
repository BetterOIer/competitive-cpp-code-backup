#include<iostream>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,opt,a[15][2];
int head[15];
long long ans[2],maans[2];
long long ANS=-9223372036854775807ll - 1;
/* struct cont{
    int whi;
    int step;
    int num;
};
deque<cont>c[2]; */
void dfs(int step){
    if(step==n){
        for(int i = 1;i<=n;i++){
            if(head[i]==1){
                ans[1]+=a[i][head[i]];
                // c[1].push_back((cont){i,head[i],a[i][head[i]]});
                if(ans[0]>=maans[0]||ans[1]>=maans[1]){
                    ANS=max(ans[0]-ans[1],ANS);
                    maans[0]=ans[0];
                    maans[1]=ans[1];
                }
                // c[1].pop_back();
                ans[1]-=a[i][head[i]];
                break;
            }
        }
        return;
    }
    for(int i = 1;i<n;i++){
        for(int j = i+1;j<=n;j++){
            if(head[i]<=1&&head[j]<=1){
                ans[step&1]+=a[i][head[i]];
                ans[step&1]+=a[j][head[j]];
                // c[step&1].push_back((cont){i,head[i],a[i][head[i]]});
                // c[step&1].push_back((cont){j,head[j],a[j][head[j]]});
                head[i]++;head[j]++;
                dfs(step+1);
                head[i]--;head[j]--;
                // c[step&1].pop_back();
                // c[step&1].pop_back();
                ans[step&1]-=a[i][head[i]];
                ans[step&1]-=a[j][head[j]];
            }
        }
    }
}
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i][0]=read();
        a[i][1]=read();
    }
    while(m--){
        ANS=-9223372036854775807ll - 1;
        ans[0]=ans[1]=0;
        opt=read();
        a[opt][0]=read();
        a[opt][1]=read();
        for(int i = 1;i<=n;i++){
            ans[0]+=a[i][head[i]];
            // c[0].push_back((cont){i,head[i],a[i][head[i]]});
            head[i]++;
            dfs(1);
            head[i]--;
            // c[0].pop_back();
            ans[0]-=a[i][--head[i]];
        }
        cout<<ANS<<endl;
    }
    return 0;
}