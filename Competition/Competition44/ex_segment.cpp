#include<iostream>
#include<map>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
map<pair<int,int>,int>M;
struct node{
    int x,y;
}segment[5000005];
int tot=0,xn,yn;
long long ans=0;
int main(){
    int q=read(),doo=read(),opt,x,y,last=0;
    while(q--){
        opt=read(),x=read(),y=read();
        x=x+doo*last;
        y=y+doo*last;
        if(opt==1){
            M[{x,y}]=++tot;
            segment[tot].x=x,segment[tot].y=y;
        }else if(opt==2){
            int whi=M[{x,y}];
            for(int i = 1;i<=tot;i++){
                if(whi==i)continue;
                if(max(x,segment[i].x)<=min(y,segment[i].y)){
                    xn=max(x,segment[i].x);
                    yn=min(y,segment[i].y);
                    M.erase({x,y});
                    M[{xn,yn}]=i;
                    segment[i].x=xn;
                    segment[i].y=yn;
                }
            }
        }else if(opt==3){
            int whi=M[{x,y}];
            ans=0;
            for(int i = 1;i<=tot;i++){
                if(whi==i)continue;
                if(max(x,segment[i].x)<=min(y,segment[i].y)){
                    xn=max(x,segment[i].x);
                    yn=min(y,segment[i].y);
                    ans+=yn-xn;
                }
            }
            cout<<ans<<endl;
            last=ans;
        }
    }
    return 0;
}