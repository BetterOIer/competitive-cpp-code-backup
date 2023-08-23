#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
bool lim[10];
bool check(int cnt){
    while(cnt){
        int nn=cnt%10;
        if(lim[nn])return false;
        cnt/=10;
    }
    return true;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int T=read();
    while(T--){
        for(int i = 0;i<=9;i++)lim[i]=false;
        int len=read(),n=read();
        for(int i = 1;i<=len;i++) lim[read()]=true;
        if(len==10)cout<<-1<<endl;
        else if(len==0)cout<<n<<endl;
        else{
            int cnt=n;
            bool flag=false;
            for(;cnt<=1000000;cnt+=n){
                if(check(cnt)){
                    cout<<cnt<<endl;
                    flag=true;
                    break;
                }
            }
            if(!flag)cout<<-1<<endl;
        }
    }
    return 0;
}