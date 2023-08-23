#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<string>
//#include<cstdin>
//#include<cmath>
//#include<stdlib>
using namespace std;
long long a[11][1011];
int g(int x){
    for(int i = x;i>=1;i--){
        if(x%i==0){
            return i;
        }
    }
    return 1;
}
int f(int n){
    return n+g(n);
}

int main(){
    //freopen("P.in","r",stdin);
    //freopen("P.out","w",stdout);
    int T;
    cin>>T;
    
    for(int i = 1;i<=T;i++){
        int n,k;
        cin>>n>>k;
        a[n][0]=n;
        for(int i = 1;i<=31;i++){
            a[n][i] = f(a[n][i-1]);
        }
        int L=0,R=30;
        while(L<=R){
            int m = L+(R-L)/2;
            if(a[n][m+k]%a[n][m]==0){
                R = m-1;
            }else if(a[n][m+k]%a[n][m]!=0){
                L = m+1;
            }
        }
        cout<<L<<endl;
    }
 	//fclose(stdin);
    //fclose(stdout);
    return 0;
} 