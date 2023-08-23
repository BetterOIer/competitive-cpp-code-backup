#include<iostream>
using namespace std;
int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n0=0;
int number(int a){
    int sum=0,l;
    while(a!=0){
        l = a%10;
        if(l==0){
            n0++;
        }else if(l==1){
            n1++;
        }else if(l==2){
            n2++;
        }else if(l==3){
            n3++;
        }else if(l==4){
            n4++;
        }else if(l==5){
            n5++;
        }else if(l==6){
            n6++;
        }else if(l==7){
            n7++;
        }else if(l==8){
            n8++;
        }else if(l==9){
            n9++;
        }
        a=(a-l)/10;
    }
    
    return 0;
}
int main(){
    int a, b;
    cin>>a>>b;
    for(int i = a;i<=b;++i){
        number(i);
    }
    cout<<n0<<" "<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<" "<<n6<<" "<<n7<<" "<<n8<<" "<<n9;
    return 0;
} 