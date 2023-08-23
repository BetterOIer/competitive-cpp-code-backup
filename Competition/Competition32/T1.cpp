#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[10];
int n,k;
bool check(){
    int ans=0;
    for(int i = 1;i<=n;i++){
        if(k%a[i]==0){
            ans++;
        }
    }
    if(ans==n){
        return false;
    }
    return true;
}
int main(){
    int t=read();
    while(t--){
        n=read(),k=read();
        for(int i = 1;i<=n;i++){
            a[i]=read();
        }
        sort(a+1,a+n+1);
        if(k>0){
            if(a[n]>0){
                cout<<"Yes"<<endl;
                continue;
            }else{
                if(check()){
                    cout<<"Yes"<<endl;
                    continue;
                }else{
                    cout<<"No"<<endl;
                    continue;
                }
            }
        }else{
            if(a[1]<0){
                cout<<"Yes"<<endl;
                continue;
            }
            else{
                if(check()){
                    cout<<"Yes"<<endl;
                    continue;
                }else{
                    cout<<"No"<<endl;
                    continue;
                }
            }
        }
    }
}