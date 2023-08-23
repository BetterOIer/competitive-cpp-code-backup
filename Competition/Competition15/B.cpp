#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int check(int len){
    if(a[len-2]>a[len]%a[len-1]) return a[len-2];
    else return a[len]%a[len-1];
}
int main(){
    int n=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    int len=unique(a+1,a+1+n)-a-1;
    if(len<=1) cout<<-1;
    else cout<<check(len);
}