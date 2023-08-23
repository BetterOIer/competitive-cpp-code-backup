#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m;
int a[N],b[N];
struct Node{int x,id;}s[N];
bool cmp(Node x,Node y){return x.x<y.x;}
signed main()
{
	cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i].x,s[i].id=i;m=n;
	sort(s+1,s+n+1,cmp);
	if (n%3==1) s[++n].x=s[n-1].x+1;
	if (n%3==2) s[++n].x=s[n-1].x+1;
	int k=n/3;
	for (int i=1;i<=k;i++) b[s[i].id]=i-1,a[s[i].id]=s[i].x-b[s[i].id];
	for (int i=k+1;i<=2*k;i++) a[s[i].id]=i-1,b[s[i].id]=s[i].x-a[s[i].id];
	for (int i=2*k+1;i<=3*k;i++) a[s[i].id]=3*k-i,b[s[i].id]=s[i].x-a[s[i].id];
	puts("YES");
	for (int i=1;i<=m;i++) cout<<a[i]<<" ";cout<<endl;
	for (int i=1;i<=m;i++) cout<<b[i]<<" ";
}
