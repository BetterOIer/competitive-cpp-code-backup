#include<iostream>
using namespace std;
long long front=0,n,cnt=0,j,k,ddz[250100];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>j>>k;
        while(front>0&&k<=ddz[front]){
            if(k==ddz[front])cnt++;
            --front;
        }
        ddz[++front]=k;
    }
    cout<<n-cnt;
    return 0;
}