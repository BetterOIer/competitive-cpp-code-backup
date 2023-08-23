#include<iostream>
const long long inf=-(1<<62);
int m,tot;
char op[2];
long long data[800005],x,t,p;
long long max(long long a,long long b)
{
    return a>b?a:b;
}
void add(int s,int k,int o,int l,int r)
{
    if(l==r)
    {
        data[o]=k;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=s) add(s,k,o<<1,l,mid);
    if(mid<s) add(s,k,o<<1|1,mid+1,r);
    data[o]=max(data[o<<1],data[o<<1|1])%p;
}
long long ask(int ll,int rr,int o,int l,int r)
{
    if(ll<=l&&rr>=r) return data[o];
    int mid=(l+r)>>1;
    long long a=inf,b=inf;
    if(mid>=ll) a=ask(ll,rr,o<<1,l,mid);
    if(mid<rr) b=ask(ll,rr,o<<1|1,mid+1,r);
    return max(a,b);
}
int main()
{
    scanf("%d %lld",&m,&p);
    for(int i=0;i<m;i++)
    {
        scanf("%s %lld",op,&x);
        if(op[0]=='A')
        {
            add(tot+1,(x+t)%p,1,1,m);
            tot++;
        }
        if(op[0]=='Q')
        {
            if(x==0) t=0;
            else t=ask(tot-x+1,tot,1,1,m)%p;
            printf("%lld\n",t);
        }
    }
    return 0;
}

