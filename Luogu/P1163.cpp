#include<iostream>
using namespace std;
int debt,per_m,mon;
bool check(double M){
    double ans=debt;
    for(int i = 1;i<=mon;i++) ans=ans*(1+M)-per_m;
    return ans<0;
}
int main(){
    cin>>debt>>per_m>>mon;
    double L=0,R=5,M;
    while(R-L>=0.0001){
        M=L+(R-L)/2;
        if(!check(M))R=M;
        else L=M;
    }
    M=100*M;
    printf("%.1f", M);
    return 0;
}