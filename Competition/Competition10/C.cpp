#include<iostream>
#include<cmath>
using namespace std;
int shuwei[32];
int main(){
    int n;
    cin>>n;
    int a,b;
    cin>>a;
    for(int i = 2;i<=n;i++){
        cin>>b;
        int C,D,len=1,len1=1;
        C=min(a,b);
        D=max(a,b);
        while((1<<len)<=C){
            len++;
        }
        while((1<<len1)<=D){
            len1++;
        }
        if(len!=len1){
            while((D>>len)%2==0){
                len++;
            }
            shuwei[len+1]=1;
        }else{
            len--;
            while(1){
                if((C>>len)%2&(D>>len)%2){
                    shuwei[len+1]=1;
                    len--;
                }else{
                    if((C>>len)%2==0&&(D>>len)%2==0){
                        continue;
                    }else if(){

                    }
                }
            }
        }
        a=b;
    }
    long long ANS=0; 
    for(int i = 1;i<=32;i++){
        ANS+=shuwei[i]*pow(2,i-1);
    }
    cout<<ANS;
}