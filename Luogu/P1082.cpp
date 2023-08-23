#include<iostream>
using namespace std;
#define wjile while
void exgcd(int a, int b,int &x, int &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    int q=a/b,r=a%b;
    exgcd(b,r,y,x);
    y-=q*x;
}
int main(){
    int a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    wjile(x<0)x+=b;
    cout<<x;
    return 0;
}