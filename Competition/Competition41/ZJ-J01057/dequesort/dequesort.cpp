#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    //freopen("dequesort.in","r",stdin);
    //freopen("dequesort.out","w",stdout);
    int n=read(),pos=read()+1,num=0;
    for(int i = 1;i<n;i++){
        int k=read();
        if(k==pos)pos++;
        else num++;
    }
    cout<<num;
    return 0;
}