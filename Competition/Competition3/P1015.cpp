#include<iostream>
#include<cmath>
using namespace std;
char x[105];
int y[105];
int jf(char[]){
    for(int i = 0,j=strlen(x);i<strlen(x);i++,j--){
        y[i] = (x[i]-'0')+(x[j]-'0');
    }for(int i = 0;i<=strlen(x);i++){
    	y[i+1]+= 
    }
    while(n5!=0){
        n6 = n6*10+n5%m;
        n5 = n5/m;
    }
    while(n6!=0){
        n5 = n5*10+n6%10;
        n6 = n6/10;
    }
    return n5;
}
int hws(const int m,int n){
    int n1=0, n2 = n, flag = 0;
    ans++;
    while(n!=0){
        n1 = n1*10+n%10;
        n = n/10;
        flag++;
    }if(ans<=30){
        if(n1==n2) return ans;
        else{
            return hws(m,jf(m,n1,n2,flag));
        }
    }
    return 0;
}
int main(){
    int n, m;
    cin>>n>>m;
    int a = hws(n,m)-1;
    if(a){
        cout<<"STEP="<<a;
    }else{
        cout<<"Impossible!";
    }
    return 0;
} 
