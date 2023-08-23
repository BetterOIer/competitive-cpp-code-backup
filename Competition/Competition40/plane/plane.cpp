#include<iostream>
#include<vector>
#include<map>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int x;
    int y;
    long long val;
};
vector<node>po;
vector<int>x,y;
map<pair<int,int>,int>M;
int main(){
    freopen("plane.in","r",stdin);
    freopen("plane.out","w",stdout);
    int n=read();
    int m=read();
    for(int i = 1,X,Y,W;i<=n;i++){
        X=read(),Y=read(),W=read();
        po.push_back((node){X,Y,W});
        x.push_back(Y);
        y.push_back(X);
        M[{X,Y}]=i;
    }
    for(int i = 1,opt,whi;i<=m;i++){
        opt=read(),whi=read();
        if(opt==1){
            for(){

            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}