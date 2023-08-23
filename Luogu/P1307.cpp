#include<iostream>
using namespace std;
int szfz(long x){
    long g=0;
    if (x>0){
        while(x!=0){
            g = 10*g + x%10;
            x = (x-x%10)/10;
        }
    }
    else if(x ==0){
        g =0;
    }
    else if(x<0){
        x = -x;
        while(x!=0){
            g = 10*g + x%10;
            x = (x-x%10)/10;
        }
        g = -g;
    }
    return g;
}
int main(){
    long n;
    cin>>n;
    cout<<szfz(n);
    return 0;
} 