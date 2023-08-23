#include<iostream>
using namespace std;
int shu[1005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            shu[i]+=shu[j];
        }
        shu[i]++;
    }
    cout<<shu[n];
    return 0;
}