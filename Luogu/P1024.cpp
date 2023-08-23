#include<iostream>
using namespace std;
double a,b,c,d;
double yysq(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
int main(){
    double x1,x2;
    cin>>a>>b>>c>>d;
    for(int i = -100;i<=100;i++){
        double L=i,R=i+1;
        x1 = yysq(L);
        x2 = yysq(L+1);
        if(!x1){
            printf("%.2lf ",L);
        }
        if(x1*x2<0){
            while(R-L>0.001){
                double M = (R+L)/2;
                if(yysq(M)*yysq(R)<= 0){
                    L=M;
                }else if(yysq(M)*yysq(R) > 0){
                    R=M;
                }
            }
            printf("%.2lf ",R);
        }
    }
    return 0;
} 