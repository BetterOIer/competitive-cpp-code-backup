#include<cstdio>
int main(){
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a*a>b*c) printf("Alice");
    else printf("Bob");
}