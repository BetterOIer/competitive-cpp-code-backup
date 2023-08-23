#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    int n=read();
    string s;
    cin>>s;
    for(int i = 1;i<n;i++){
        int maxl=0;
        bool flag=false;
        for(int j = 1;j<=n-i;j++){
            if(s[j-1]==s[j+i-1]){
                maxl=j-1;
                flag=true;
                break;
            }
        }
        if(!flag)maxl=n-i;
        cout<<maxl<<endl;
    }
}