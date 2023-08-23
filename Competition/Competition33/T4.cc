#include<iostream>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[100005];
int  kb[50];
int main(){
    int n=read(),k=read(),m=read(),opt,x,y;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=m;i++){
        opt=read();
        if(opt==1){
            x=read(),y=read();
            a[x]=y;
        }else{
            bool flag=false;
            int ans=0,minn=2147483647;
            int p1=1,p2=0;
            memset(kb,0,sizeof(kb));
            while(p2<=n){
                while(!flag&&p2<=n){
                    kb[a[++p2]]++;
                    if(kb[a[p2]]==1){
                        ans++;
                        if(ans==k){
                            flag=true;
                            minn=min(minn,p2-p1+1);
                        }
                    }
                }
                while(flag&&p1<=n){
                    kb[a[p1]]--;
                    if(kb[a[p1++]]==0){
                        ans--;
                        if(ans!=k){
                            flag=false;
                        }else{
                            minn=min(minn,p2-p1+1);
                        }
                    }
                }
            }
            if(minn>n)cout<<-1<<endl;
            else cout<<minn<<endl;
        }
    }
}