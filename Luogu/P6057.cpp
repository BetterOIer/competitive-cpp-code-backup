#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int pos[100005];
long long ans;
int main(){
    int n=read(),m=read();
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        pos[x]++,pos[y]++;
    }
    for(int i=1;i<=n;i++)
        ans+=(1ll*pos[i]*(n-1-pos[i]));
    cout<<1ll*n*(n-1)*(n-2)/6-(ans>>1);
    return 0;
}