#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int N = 15;
int dp[12][12]
void init(){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<=i;j++){
            if(!j)f[i][j]=1;
        }
    }
}
int main(){
    init();
    return 0;
}