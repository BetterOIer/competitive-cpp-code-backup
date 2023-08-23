#include<iostream>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    long long t=read();
    for(;t--;){
        long long n=read();
        long long cnt=n;
        while(true){
            while(cnt%10==0)cnt/=10;
            if(cnt%5==0){
                cnt*=4;
                n*=4;
            }else{
                break;
            }
        }
        cout<<n<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
