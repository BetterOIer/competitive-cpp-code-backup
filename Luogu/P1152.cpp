#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1001];
int main(){
    int n;
    cin>>n;
    int a1,a2;
    cin>>a1;
    for(int i = 1;i<=n-1;i++){
        cin>>a2;
        a[i] = abs(a1-a2);
        a1 = a2;
    }
    sort(a+1,a+n);
    if(a[1]==1&&a[n-1]==n-1){
        cout<<"Jolly";
        return 0;
    }
    cout<<"Not jolly";
    return 0;
} 