#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[6];
int main(){
    int T=read();
    while(T--){
        a[1]=read(),a[2]=read(),a[3]=read(),a[4]=read();
        sort(a+1,a+4+1);
        if((a[1]+1==a[2]&&a[2]+1==a[3])||(a[2]+1==a[3]&&a[3]+1==a[4])){
            cout<<1<<endl;
            continue;
        }else if((a[1]+1==a[2]&&a[3]==a[4])||(a[3]+1==a[4]&&a[1]==a[2])||(a[1]+1==a[4]&&a[2]==a[3])){
            cout<<1<<endl;
            continue;
        }else if((a[1]+2==a[2]&&a[3]==a[4])||(a[3]+2==a[4]&&a[1]==a[2])||(a[1]+2==a[4]&&a[2]==a[3])){
            cout<<1<<endl;
            continue;
        }
        cout<<0<<endl;
    }
    return 0;
}
