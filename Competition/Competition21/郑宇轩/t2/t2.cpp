#include<iostream>
using namespace std;
struct node{
    unsigned long long he;
    int gs;
    long long ctr1;
    long long ctr2;
}a[41];
bool hav[41];
int re[41],tot=0;
unsigned long long ans;
int main(){
    //freopen("t2.in","r",stdin);
    //freopen("t2.out","w",stdin);
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>u>>v;
        a[u].he+=v;
        a[u].gs++;
        hav[u]=true;
    }
    for(int i = 1;i<=40;i++){
        if(hav[i]) re[++tot]=i;
    }
    for(int i = 1;i<=tot;i++){
        a[re[i]].ctr1=(1<<a[re[i]].gs)-1;
        a[re[i]].ctr2=1<<(a[re[i]].gs-1);
    }
    for(long long i = 0;i<=(1<<tot)-1;i++){
        long long cnt=i;
        int po[41],to=0;
        int fl=0;
        while(cnt){
            fl++;
            if(cnt&1) po[++to]=fl;
            cnt=cnt>>1;
        }
        if(to>=m){
            long long mul=1;
            for(int i = 1;i<=to;i++) mul*=a[re[po[i]]].ctr1;
            for(int i = 1;i<=to;i++) ans+=(a[re[po[i]]].he*mul/a[re[po[i]]].ctr1*a[re[po[i]]].ctr2);
        }
    }
    cout<<ans;
    //fclose(stdin);
    //fclose(stdout);
}