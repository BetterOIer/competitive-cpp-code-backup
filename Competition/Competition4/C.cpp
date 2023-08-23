#include<iostream>
#include<cstdio>
int a[100000];
double mon[10000][2];
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    mon[1][0]=100;
    mon[1][1]=a[1]; 
    for(int i=2;i<=n;i++)
    {
        mon[i][0]=mon[i-1][0]>(mon[i-1][1]/a[i])*100? mon[i-1][0]:(mon[i-1][1]/a[i])*100; 
        mon[i][1]=max(mon[i-1][1],mon[i-1][0]*a[i]/100);
    }
    printf("%.2f",max(mon[n][0],(mon[n][1]/a[n])*100)); 
    return 0;
}
