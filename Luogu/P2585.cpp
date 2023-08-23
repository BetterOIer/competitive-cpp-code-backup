#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[500010];
int n,cnt,tree[500010][2];
int f[500010][2],root;
void build(int &x)
{
    x=++cnt;
    int opt=str[cnt]-'0';
    if(opt==0)return ;
    if(opt==1)build(tree[x][1]);
    if(opt==2)build(tree[x][1]),build(tree[x][2]);
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    build(root);
    for(int i=n;i>=1;i--)
    {
        f[i][1]=f[tree[i][1]][0]+f[tree[i][2]][0]+1;
        f[i][0]=max(f[tree[i][1]][1]+f[tree[i][2]][0],f[tree[i][2]][1]+f[tree[i][1]][0]);
    }
    printf("%d ",max(f[1][1],f[1][0]));
    for(int i=n;i>=1;i--)
    {
        f[i][1]=f[tree[i][1]][0]+f[tree[i][2]][0]+1;
        f[i][0]=min(f[tree[i][1]][1]+f[tree[i][2]][0],f[tree[i][2]][1]+f[tree[i][1]][0]);
    }
    printf("%d",min(f[1][1],f[1][0]));
    return 0;
}
