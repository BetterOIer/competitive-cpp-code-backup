#include<iostream>
#include<algorithm>
using namespace std;
int a[21];
int main(){
    int m, n;
    float ans=0.00,sum=0.00;
    cin>>m>>n;
    for(int i = 1;i<=m;++i){
        for(int w = 1;w<=n;++w){
            cin>>a[w];
        }
        sort(a+1,a+n+2);
        for(int w = 2;w<=n-1;w++){
            ans+=a[w];
        }
        ans = ans/(n-2);
        sum = sum>ans? sum:ans;
        ans = 0;
    }
    printf("%.2f\n", sum);
    return 0;
}