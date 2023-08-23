#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    freopen("ex_line2.in","r",stdin);
    int t=read(),ans=0;
    int n;
    for(int i = 1;i<=307;i++){
        n=read();
        for(int i = 1,x,y;i<=n;i++){
            y=read(),x=read();
        }
    }
    n=read();
    cout<<n<<endl;
    for(int i = 1,x,y;i<=n;i++){
        y=read(),x=read();
        cout<<y<<" "<<x<<endl;
    }
}