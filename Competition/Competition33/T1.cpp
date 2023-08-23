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
    for(int i = 0;i<12;i++){
        for(int j = 0;j<60;j++){
            for(int w = 0;w<60;w++){
                t1u=3600*i+60*j+w;
                B1=120;
                t2u=720*j+12*w;
                B2=120;
                t3u=720*w;
                B3=120;
                A1=abs(t1u-t2u);
                if(A1>Bif)A1=Bif*2-A1;
                A2=abs(t1u-t3u);
                if(A2>Bif)A2=Bif*2-A2;
                A3=abs(t3u-t2u);
                if(A3>Bif)A3=Bif*2-A3;
                yuefen(A1,B1);
                yuefen(A2,B2);
                yuefen(A3,B3);
                if(A1==a1&&A2==a2&&A3==a3&&B1==b1&&B2==b2&&B3==b3){
                    T.push_back((node){i,j,w});
                }
            }
        }
    }
}
int main(){
    int t=read();
    while(t--){
        T.clear();
        scanf("%d/%d %d/%d %d/%d",&a1,&b1,&a2,&b2,&a3,&b3);
        check();
        cout<<T.size()<<endl;
        for(node i:T){
            printf("%02d:%02d:%02d\n",i.h,i.m,i.s);
        }
    }
}