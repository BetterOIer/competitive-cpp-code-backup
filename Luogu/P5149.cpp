#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
string s;
int n,a[N],b[N];
long long ans;
map<string,int>m;

void merge_sort(int left,int right)
{
	if(left>=right) return;
	int mid = (right-left)/2+left;
	merge_sort(left,mid);
	merge_sort(mid+1,right);
	int i=left,j=mid+1,k=left;
	while(i<=mid && j<=right){
		if(a[i]<a[j]) b[k++]=a[i++];
		else b[k++] = a[j++],ans+=mid-i+1;
	}
	while(i<=mid) b[k++] = a[i++];
	while(j<=right) b[k++] = a[j++];
	for(int i=left;i<=right;i++) a[i]=b[i];
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		m[s]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		a[m[s]]=i;
	}
	merge_sort(1,n);
	cout<<ans;
	return 0;
}
