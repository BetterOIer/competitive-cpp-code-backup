/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[100005];
int main(){
    int T=read();
    while(T--){
        int n=read(),k=read();
        for(int i = 1;i<=n;i++) a[i]=read();
        int pos=1,ans=0;
        for(int i = 1;i<=n;i++){
            if(pos==a[i]){
                pos++;
            }else{
                ans++;
            }
        }
        cout<<ceil(1.0*ans/k)<<endl;
    }
}