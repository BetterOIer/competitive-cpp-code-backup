#include<iostream>
using namespace std;
int a[10001];
int main(){
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int x = n;
    for(int i = 1;i<=n-1;i++){
        for(int w = 1;w<=n-i;w++){
            if(a[w]>a[w+1]){
                int b = a[w];
                a[w] = a[w+1];
                a[w+1] = b;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
} 