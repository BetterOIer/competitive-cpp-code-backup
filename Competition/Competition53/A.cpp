#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[105];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++){
            a[i]=read()&1;
        }
        int num=0;
        for(int i = 1;i<n;i++){
            if(a[i]==a[i+1]&&a[i]==1){
                num++;
            }else if(a[i]==a[i+1]&&a[i]==0){
                num++;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}