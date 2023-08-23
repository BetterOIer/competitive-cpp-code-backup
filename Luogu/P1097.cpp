#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
int main(){
    int n,cnt=0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[n+1]=-1;
    for(int i = 2;i<=n+1;i++){
        if(a[i]!=a[i-1]){
            cout<<a[i-1]<<" "<<++cnt<<endl;
            cnt=0;
        }else {
            cnt++;
        }
    }
}