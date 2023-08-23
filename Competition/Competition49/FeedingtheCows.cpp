#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int poG[100005],poH[100005];
int n,k;
int main(){
    int T=read();
    while(T--){
        n=read(),k=read();
		string s;
		cin>>s;
		for(int i = 0;i<n;i++){
			if(s[i]=='H')poH[i-1]++,poH[i]++,poH[i+1]++;
			else poG[i-1]++,poG[i]++,poG[i+1]++;
		}
    }
}