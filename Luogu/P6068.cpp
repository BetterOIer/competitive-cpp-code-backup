#include<iostream>
#include<cmath>
using namespace std;
int t,n;
bool isprime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=5)cout<<-1<<endl;
        else if(isprime(n))cout<<1<<endl;
        else {
            int ans=0;
            for(int i=1;i*i<=n;i++){
                if(n%i==0){
                    if(i>=6)ans=max(ans,n/i);
                    if(n/i>=6)ans=max(ans,i);
                }
            }
            if(ans)cout<<ans<<endl;
        }

    }
    return 0;
}
