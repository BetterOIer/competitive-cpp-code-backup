//*** Le vent se lève, il faut tenter de vivre! ***
#include<iostream>
double a[8],s,ans=1;
int main(){
    for(int i = 1;i<=7;i++) scanf("%lf",a+i),s+=a[i];
    for(int i = 1;i<=6;i++) ans=ans*a[i]/(s+1-i)*double(i);
    printf("%.3lf\n",ans*a[7]*7.0);
}