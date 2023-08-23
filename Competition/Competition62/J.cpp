#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m,tot;
bool die_a[10],die_b[10];
int a[10],b[10],ha[10],hb[10],sa[10],sb[10];
void dfs(int pa,int pb,bool who,ld &A,ld &B,ld &P){
    A=B=P=0;
    if(!pa&&!pb){
        P=1,A=0,B=0;
        return;
    }else if(!pa){P=0,A=0,B=1;
        return;
    }else if(!pb){P=0,A=1,B=0;
        return;
    }
    if(!who){
        int loc=0,sum=1555;
        for(int i=1;i<=n;i++){
            if(!die_a[i]&&sum>sa[i]){
                sum=sa[i],loc=i;
            }
        }
        for(int i=1;i<=m;i++){
            if(!die_b[i]){
                //if(n==pa&&m==pb)puts("....................\n");
                //printf("A%d->B%d\nHP:%d %d\n%d %d %d\n->\n",loc,i,ha[1],ha[2],hb[1],hb[2],hb[3]);
                sa[loc]++;
                //sb[i]++;
                ha[loc]-=b[i];
                hb[i]-=a[loc];
                if(ha[loc]<=0)die_a[loc]=1,pa--;
                if(hb[i]<=0)die_b[i]=1,pb--;
                //printf("HP:%d %d\n%d %d %d\n\n",ha[1],ha[2],hb[1],hb[2],hb[3]);
                ld aa,bb,pp;
                dfs(pa,pb,who^1,aa,bb,pp);
                if(ha[loc]<=0)die_a[loc]=0,pa++;
                if(hb[i]<=0)die_b[i]=0,pb++;
                A+=aa/pb;
                B+=bb/pb;
                P+=pp/pb;
                ha[loc]+=b[i];
                hb[i]+=a[loc];
                sa[loc]--;
                //sb[i]--;
            }
        }
    }else{
        int loc=0,sum=1555;
        for(int i=1;i<=m;i++){
            if(!die_b[i]&&sum>sb[i]){
                sum=sb[i],loc=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(!die_a[i]){
                //if(n==pa&&m==pb)puts("....................\n");
                //printf("B%d->A%d\nHP:%d %d\n%d %d %d\n->\n",loc,i,ha[1],ha[2],hb[1],hb[2],hb[3]);
                sb[loc]++;
                //sa[i]++;
                hb[loc]-=a[i];
                ha[i]-=b[loc];
                if(hb[loc]<=0)die_b[loc]=1,pb--;
                if(ha[i]<=0)die_a[i]=1,pa--;
                //printf("HP:%d %d\n%d %d %d\n\n",ha[1],ha[2],hb[1],hb[2],hb[3]);
                ld aa,bb,pp;
                dfs(pa,pb,who^1,aa,bb,pp);
                if(hb[loc]<=0)die_b[loc]=0,pb++;
                if(ha[i]<=0)die_a[i]=0,pa++;
                A+=aa/pa;
                B+=bb/pa;
                P+=pp/pa;
                hb[loc]+=a[i];
                ha[i]+=b[loc];
                sb[loc]--;
                //sa[i]--;
            }
        }
    }
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=ha[i]=read();
    }
    for(int i=1;i<=m;i++){
        b[i]=hb[i]=read();
    }
    ld A1=0,A2=0,B1=0,B2=0,P1=0,P2=0;
    if(n>=m)dfs(n,m,0,A1,B1,P1);
    if(n<=m)dfs(n,m,1,A2,B2,P2);
    if(n!=m)printf("%.12Lf\n%.12Lf\n%.12Lf",A1+A2,B1+B2,P1+P2);
    else printf("%.12Lf\n%.12Lf\n%.12Lf",(A1+A2)*0.5,(B1+B2)*0.5,(P1+P2)*0.5);
}
