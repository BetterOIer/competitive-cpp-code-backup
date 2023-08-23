#include<iostream>
#include<algorithm>  
using namespace std;
int a[10010];
int main(){
    int m ,n;
    cin>>n>>m;
	for(int i=1;i<=n;++i)	cin>>a[i];
	for(int i=1;i<=m;++i)	next_permutation(a+1,a+1+n);
	for(int i=1;i<n;++i)	cout<<a[i]<<' ';
    return 0;
}