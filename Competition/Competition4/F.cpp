#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int k,a,b,c;
    cin>>k;
    a=1,b=1;
    while(a+b<=k)
    {
        c=a+b;
        a=b;
        b=c;
    }
    printf("m=%d\nn=%d\n",a,b);
    return 0;
}
