#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
    unsigned long long A=0,B=0;
    while(true){
        int a=-1,b=-1,c=-1;
        while(true){
            c=b;
            b=a;
            a=rand()%2;
            if(a==0&&b==0&&c==1){
                A++;
                break;
            }
            if(a==1&&b==0&&c==0){
                B++;
                break;
            }
        }
        double ans=1.0*A/B;
        cout<<floor(ans)<<endl;
    }
}