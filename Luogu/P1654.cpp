#include<iostream>
using namespace std;
int n;
double base[100005],s1[1000005],s2[1000005],s3[1000005];
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>base[i];
    for(int i = 1;i<=n;i++) {
        s1[i]=(s1[i-1]+1)*base[i];
        s2[i]=(s2[i-1]+2*s1[i-1]+1)*base[i];
        s3[i]=s3[i-1]+(3*(s1[i-1]+s2[i-1])+1)*base[i];
    }
    printf("%.1lf",s3[n]);
    return 0;
}