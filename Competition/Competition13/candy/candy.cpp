#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,L,R;
    cin>>n>>L>>R;
    int k=R-L;
    L=L%n+n;
    R=L+k;
    if(R<=2*n-1){
        cout<<R-n;
    }else{
        cout<<n-1;
    }
    return 0;
}