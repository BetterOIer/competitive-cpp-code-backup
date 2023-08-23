#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
struct f{
	int data,xh;
}s[8005];
int main(){
	int a,q;
	 scanf("%d%d",&a,&q);
	for(int i=1;i<=a;i++){
		s[i].data=read();
	}
	while(q--){
		int opt,x,v;
		opt=read();
		if(opt==1){
			x=read();
			v=read();
			s[x].data=v;
		}
		if(opt==2){
			x=read();
			int c=1;
			for(int i=1;i<x;i++) if(s[x].data>=s[i].data) c++;
			for(int i=x+1;i<=a;i++) if(s[x].data>s[i].data) c++;
			printf("%d\n",c);
		}
	}
	return 0;
}