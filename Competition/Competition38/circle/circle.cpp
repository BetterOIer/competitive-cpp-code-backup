#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,a[200005];
//int po[200005];
int main(){
    int minn=4500005,minpo=0;
    int po1=0,po2=0,count=0,st=0;
    n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        if(a[i]==1){
            po2=po1,po1=i,++count;
            if(count==1)st=i;
            else if(!count)continue;
            else{
                if(minn>po1-po2){
                    minn=po1-po2;
                    minpo=po2;
                }
            }
        }
    }
    if(count<2){
        cout<<0;
        return 0;
    }
    if(minn>st+n-po1){
        minn=st+n-po1;
        minpo=po1;
    }
    long long ans=0;
    /* if(count&1==0){ */
    int k=n>>1,count1=0;
    for(int i = 1;i<=k;i++){
        if(a[(minpo+i-1)%n+1]==1){
            ans+=abs(i-count1-1);
            count1++;
        }
    }
    count1=0;
    for(int i = 1;i<=k;i++){
        if(a[(minpo-i+n-1)%n+1]==1){
            ans+=abs(i-1-count1);
            count1++;
        }
    }
    cout<<ans;
}