#include<iostream>
#include<cmath>
using namespace std;
bool a[1025][1025]={1};
int m;
void xs(int n){
    for(int i = 1;i<=pow(2,n);i++){
        for(int w = 1;w<=pow(2,n);w++){
            if(w<pow(2,n)){
                if(a[i][w]){
                    cout<<"0"<<" ";
                }else{
                    cout<<"1"<<" ";
                }
            }else{
                if(a[i][w]){
                    cout<<"0"<<endl;
                }else{
                    cout<<"1"<<endl;
                }
            }  
        }
    }
}
int shemian(int n, int x, int y){
    for(int i = 1;i<=pow(2,n-1);i++){
        for(int w = 1;w<=pow(2,n-1);w++){
            a[i+y-1][w+x-1]=1;
        }
    }
    if(n==1){
        return 0;
    }
    return (shemian(n-1,x+pow(2,n-1),y),shemian(n-1,x,y+pow(2,n-1)),shemian(n-1,x+pow(2,n-1),y+pow(2,n-1)));
}

int main(){
    int n;
    cin>>n;
    m=n;
    shemian(n, 1, 1);
    xs(n);
    return 0;
}