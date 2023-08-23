#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[15];
int main(){
    int t=read(),l,y;
    while(t--){
        l=read(),y=read();
        int L=10,R=l;
        while(L<R){
            int mid=(L+R)>>1;
            for(int i = 1;i<=14;i++)a[i]=0;
            int n=l,tot=1;
            while(n){
                a[1]+=min(n,mid);
                for(int i = 1;i<=tot;i++){
                    while(a[i]>=mid){
                        a[i]-=mid;
                        a[i+1]+=1;
                        if(i+1>tot)tot=i+1;
                    }
                }
                n-=min(n,mid);
            }
            bool flag=true;
            int origin=0;
            for(int i = 1;i<=tot&&flag;i++){
                if(a[i]>10){
                    flag=false;
                }
                origin=origin*10+a[i];
            }
            if(origin>=y&&flag){
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        cout<<L<<endl;
    }
}