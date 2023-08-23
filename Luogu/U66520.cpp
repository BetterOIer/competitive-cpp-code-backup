#include<iostream>
using namespace std;
bool a[1000600];
bool b[1000600];
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int main(){
    string s;
    long long n=read(),k=read();
    cin>>s;
    if(n==1&&k){
        cout<<0;
        return 0;
    }
    for(long long i = 1;i<=n;i++){
        a[i]=s[i-1]-'0';
    }
    for(long long i = 1;i<=50000;i++){
        for(long long j = 2;j<n;j++){
            int fa=0;
            if(a[j-1])fa++;
            if(a[j+1])fa++;
            if(fa==1)b[j]=true;
            else b[j]=false;
        }
        int fa=0;
        if(a[n])fa++;
        if(a[2])fa++;
        if(fa==1)b[1]=true;
        fa=0;
        if(a[n-1])fa++;
        if(a[1])fa++;
        if(fa==1)b[n]=true;
        for(long long j = 1;j<=n;j++){
            a[j]=b[j];
            cout<<a[j];
            b[j]=false;
        }
        cout<<endl;
    }
}