#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[1000005];
int main(){
	int n=read();
	for(int i = 1;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
    return 0;
}