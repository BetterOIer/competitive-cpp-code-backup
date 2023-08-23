#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int h[200005];
int used[20005];
int main(){
    int n=read(),x=read();
    for(int i = 1;i<=n;i++){
        h[i]=read();
    }
    for(int i = 1;i<=n;i++){
        if(used[i]==h[i])continue;
        bool flag =true;
        for(int j = 1;j<=x&&flag;j++){
            if(used[i]>=h[i+1]){
                flag=false;
            }
        }
    }
}