#include<iostream>
using namespace std;
int cnt[27];
const int mod = 1e9+7;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
unsigned long long ANS1=1,ANS2=1;
int main(){
    int n;
	string s;
	cin>>n>>s;
	for(int i =0;i<=s.length()-1;i++){
		cnt[s[i]-'a'+1]++;
	}
	for(int i = 1;i<=26;i++){
		if(cnt[i]){
			for(int j = cnt[i]/2;j<=cnt[i];j++){
				ANS1=ANS1*j/* %mod */;
			}
		}
	}
	for(int i = 1;i<=n/2;i++){
		ANS1=ANS1*i/* %mod */;
	}
	for(int i = 1;i<=n;i++){
		ANS2=ANS2*i/* %mod */;
	}
	cout<<ANS2-ANS1;
}