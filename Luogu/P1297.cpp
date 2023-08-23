//*** Le vent se lève, il faut tenter de vivre! ***
#include<iostream>
using namespace std;
int n,A,B,C,a[10000008];
int main(){
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
    for (int i = 2; i <= n; i++)
        a[i] = ((long long) a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
        a[i] = a[i] % C + 1;
    a[n+1]=a[1];
    double ans=0,ANS=0;
    for(int i = 1;i<=n;i++){
        ans=1.0*(min(a[i],a[i+1]))/(1LL*a[i]*a[i+1]);
        ANS+=ans;
    }
    printf("%.3lf\n",ANS);
}