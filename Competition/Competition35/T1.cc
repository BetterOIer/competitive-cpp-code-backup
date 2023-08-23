#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[1000005],b[1000005],tot=0;
int main(){
    freopen("numgameEX.in","r",stdin);
    freopen("numgameEX.out","w",stdout);
    int t=read(),l,y;
    while(t--){
        l=read(),y=read();
        int hal=sqrt(l);
        for(int i = 1;i<=hal;i++){
            if(l%i==0){
                a[++tot]=i;
                a[++tot]=l/i;
            }
        }
        for(int i = 1,p1=0,p2=tot+1;i<=tot;i++){
            if(i%2==0) b[--p2]=a[i];
            else b[++p1]=a[i];
        }
        int L=1,R=tot;
        while(L<R){
            int mid=(L+R)>>1;
            for(int i = 1;i<=14;i++)a[i]=0;
            int n=l,cnt=1;
            do{
                a[cnt++]=n%b[mid];
                n/=b[mid];
            }while(n);
            bool flag=true;
            int origin=0;
            for(int i = cnt-1;i>=1&&flag;i--){
                if(a[i]>10) flag=false;
                origin=origin*10+a[i];
            }
            if(origin>=y&&flag) L=mid+1;
            else R=mid-1;
        }
        cout<<b[L-1]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}