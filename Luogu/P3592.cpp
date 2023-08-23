#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
long long pos[63]={1},n,m;
int main(){
    for(long long i = 1;i<=63;i++) pos[i]=1LL*pos[i-1]*2;
    long long T=read();
    while(T--){
        n=read(),m=read();
        if(n>63){cout<<"No\n";continue;}
        bool flag=true;
        for(long long i = 0;i<n;i++){
            if(pos[i]>m){
                cout<<"No\n";
                flag=false;
                break;
            }
        }
        if(!flag)continue;
        cout<<"Yes\n";
        for(long long i = 0;i<n;i++) cout<<pos[i]<<" ";
        cout<<endl;
    }
}