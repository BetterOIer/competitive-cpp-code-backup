#include<iostream>
using namespace std;
int n,a1[100010],a2[100010],feiwu[100010],f[100010],sb[100010],len;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a1[i]);
        feiwu[a1[i]]=i;
    }
    for(int i=1;i<=n;i++)
    scanf("%d",&a2[i]);
    for(int i=1;i<=n;i++)
    {
        if(feiwu[a2[i]]>sb[len])
        {
            sb[++len]=feiwu[a2[i]];
            f[i]=len;
            continue;
        }
        int k=lower_bound(sb+1,sb+len+1,feiwu[a2[i]])-sb;
        sb[k]=feiwu[a2[i]];
        f[i]=k;
    }
    printf("%d\n",len);
    return 0;
}
