#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int Bif=180*120;
int a1,a2,a3,b1,b2,b3;
int t1u,t2u,t3u;
int A1,A2,A3,B1,B2,B3;
struct node{
    int h;
    int m;
    int s;
};
vector<node> T;
void yuefen(int &up,int &down){
	int x=up,y=down,big=(x>y?x:y);
	for(int i=big;i>=1;i--){
		if(x%i==0&&y%i==0){
			x/=i;
			y/=i;
		}
	}
    up=x,down=y;
}
void check(){
    for(int i =0;i<360;i++){
        t1u=i*120;

        t2u=t1u+a1>Bif?2*Bif-t1u+a1:t1u+a1;//bigger 2BIf
        t3u=t1u+a2>Bif?2*Bif-t1u+a2:t1u+a2;
        if(abs(t2u-t3u)==a3){
            
        }

        t3u=t1u-a2<0?a2-t1u:t1u-a2;
        if(abs(t2u-t3u)==a3){
            
        }

        t2u=t1u-a1<0?a1-t1u:t1u-a1;
    }
}
int main(){
    int t=read();
    while(t--){
        T.clear();
        scanf("%d/%d %d/%d %d/%d",&a1,&b1,&a2,&b2,&a3,&b3);
        int f=120/b1;
        b1=120;
        a1*=f;
        int f=120/b2;
        b2=120;
        a2*=f;
        int f=120/b3;
        b3=120;
        a3*=f;
        check();
        cout<<T.size()<<endl;
        for(node i:T){
            printf("%02d:%02d:%02d\n",i.h,i.m,i.s);
        }
    }
}